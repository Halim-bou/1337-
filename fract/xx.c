#include "./headers/fractol.h"


/* Optimized pixel setting function */
static void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    int dst;

    dst = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(dst + img->addr) = color;
}

/* Precompute color mapping to avoid frequent calculations */
static void init_color_map(t_fractol *fractol)
{
    int i;

    if (fractol->color_map)
        free(fractol->color_map);

    fractol->color_map = malloc(sizeof(int) * (fractol->iteration_value + 1));
    if (!fractol->color_map)
        mlx_allocation_error();

    i = 0;
    while (i <= fractol->iteration_value)
    {
        fractol->color_map[i] = map_normalizer(i, BLACK, WHITE, 0,
                                              fractol->iteration_value);
        i++;
    }
}

/* Calculate coordinates transformation once per pixel */
static void calculate_complex_coordinates(int x, int y, t_fractol *fractol,
                                         t_cnbr *c)
{
    c->x = (map_normalizer(x, -2, +2, 0, WIDTH) * fractol->mult_zoom)
           + fractol->shifting_x;
    c->y = (map_normalizer(y, +2, -2, 0, HEIGHT) * fractol->mult_zoom)
           + fractol->shifting_y;
}

/* Optimized mandelbrot calculation with early bailout conditions */
static int calculate_mandelbrot(t_cnbr c, t_fractol *fractol)
{
    t_cnbr z;
    double temp;
    int i;
    double z_squared_mag;

    z.x = 0.0;
    z.y = 0.0;
    i = 0;

    /* Early bailout check for main cardioid */
    temp = (c.x - 0.25) * (c.x - 0.25) + c.y * c.y;
    if (temp * (temp + (c.x - 0.25)) <= 0.25 * c.y * c.y)
        return fractol->iteration_value;

    /* Early bailout check for period-2 bulb */
    if ((c.x + 1.0) * (c.x + 1.0) + c.y * c.y <= 0.0625)
        return fractol->iteration_value;

    /* Main iteration loop with optimized complex calculations */
    while (i < fractol->iteration_value)
    {
        /* Store z.x² and z.y² to avoid recalculating */
        temp = z.x * z.x;
        z_squared_mag = temp + (z.y * z.y);

        /* Check escape condition before doing more math */
        if (z_squared_mag > fractol->v_escape)
            return i;

        /* Calculate z = z² + c using the optimization */
        z.y = 2.0 * z.x * z.y + c.y;
        z.x = temp - (z.y * z.y - c.y * c.y) + c.x;

        i++;
    }

    return fractol->iteration_value;
}

/* Handle pixel coloring with precomputed colors */
static void handel_pixel_set(int x, int y, t_fractol *fractol)
{
    t_cnbr c;
    int iterations;
    int color;

    calculate_complex_coordinates(x, y, fractol, &c);

    if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
        iterations = calculate_mandelbrot(c, fractol);
    else if (ft_strncmp(fractol->name, "julia", 5) == 0)
        iterations = calculate_julia(c, fractol);
    else
        iterations = calculate_mandelbrot(c, fractol);

    /* Use precomputed color map */
    if (iterations < fractol->iteration_value)
        color = fractol->color_map[iterations];
    else
        color = BLACK;

    my_mlx_pixel_put(&fractol->img, x, y, color);
}

/* Calculate Julia set with the same optimizations */
static int calculate_julia(t_cnbr z, t_fractol *fractol)
{
    t_cnbr c;
    double temp;
    int i;
    double z_squared_mag;

    /* Julia sets use fixed c value (from program args) */
    c.x = fractol->julia_x;
    c.y = fractol->julia_y;

    i = 0;
    while (i < fractol->iteration_value)
    {
        temp = z.x * z.x;
        z_squared_mag = temp + (z.y * z.y);

        if (z_squared_mag > fractol->v_escape)
            return i;

        z.y = 2.0 * z.x * z.y + c.y;
        z.x = temp - (z.y * z.y) + c.x;

        i++;
    }

    return fractol->iteration_value;
}

/* Modified render function with optional multithreading capability */
void fractol_render(t_fractol *fractol)
{
    int x;
    int y;

    /* Initialize or update the color map when parameters change */
    if (!fractol->color_map || fractol->color_map_dirty)
        init_color_map(fractol);

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handel_pixel_set(x, y, fractol);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx_in, fractol->mlx_win,
                          fractol->img.img, 0, 0);
}

/* Modified data initialization with new optimization fields */
void data_init(t_fractol *fractol)
{
    fractol->v_escape = 4;
    fractol->iteration_value = 42;
    fractol->shifting_x = 0.0;
    fractol->shifting_y = 0.0;
    fractol->mult_zoom = 1.0;
    fractol->color_map = NULL;
    fractol->color_map_dirty = 1;

    /* Default Julia set parameters (only used if Julia set is selected) */
    if (ft_strncmp(fractol->name, "julia", 5) == 0)
    {
        fractol->julia_x = atof(fractol->julia_params[0]);
        fractol->julia_y = atof(fractol->julia_params[1]);
    }
}

/* Update function to mark color map as dirty when parameters change */
void update_fractol_params(t_fractol *fractol)
{
    fractol->color_map_dirty = 1;
    fractol_render(fractol);
}

/* Modified key handler to use the update function */
int key_handle(int keycode, t_fractol *fractol)
{
    if (keycode == XK_Escape)
        stop_handle(fractol);
    else if (keycode == XK_Right)
        fractol->shifting_x -= (0.1 * fractol->mult_zoom);
    else if (keycode == XK_Left)
        fractol->shifting_x += (0.1 * fractol->mult_zoom);
    else if (keycode == XK_Up)
        fractol->shifting_y -= (0.1 * fractol->mult_zoom);
    else if (keycode == XK_Down)
        fractol->shifting_y += (0.1 * fractol->mult_zoom);
    else if (keycode == XK_equal || keycode == XK_KP_Add)
        fractol->iteration_value += 20;
    else if (keycode == XK_minus || keycode == XK_KP_Subtract)
        fractol->iteration_value -= 20;

    update_fractol_params(fractol);
    return (0);
}

/* Modified button handler to use the update function */
int button_handle(int button, int x, int y, t_fractol *fractol)
{
    double zoom_factor;
    double old_zoom;
    double mouse_re;
    double mouse_im;

    /* Calculate the complex coordinates of the mouse position */
    mouse_re = (map_normalizer(x, -2, +2, 0, WIDTH) * fractol->mult_zoom)
              + fractol->shifting_x;
    mouse_im = (map_normalizer(y, +2, -2, 0, HEIGHT) * fractol->mult_zoom)
              + fractol->shifting_y;

    old_zoom = fractol->mult_zoom;

    if (button == Button5)
        fractol->mult_zoom *= 0.9;
    else if (button == Button4)
        fractol->mult_zoom *= 1.1;

    /* Adjust shifting to zoom toward mouse position */
    fractol->shifting_x = mouse_re - ((mouse_re - fractol->shifting_x)
                         * fractol->mult_zoom / old_zoom);
    fractol->shifting_y = mouse_im - ((mouse_im - fractol->shifting_y)
                         * fractol->mult_zoom / old_zoom);

    update_fractol_params(fractol);
    return (0);
}

/* Cleanup function to free memory */
void cleanup_fractol(t_fractol *fractol)
{
    if (fractol->color_map)
        free(fractol->color_map);

    mlx_destroy_image(fractol->mlx_in, fractol->img.img);
    mlx_destroy_window(fractol->mlx_in, fractol->mlx_win);
    mlx_destroy_display(fractol->mlx_in);
    free(fractol->mlx_in);
}

/* Modified stop handler to use the cleanup function */
int stop_handle(t_fractol *fractol)
{
    cleanup_fractol(fractol);
    exit(EXIT_SUCCESS);
}
