/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:40:30 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 18:05:08 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	update_fractol_params(t_fractol *fractol)
{
	fractol_render(fractol);
}

void	cleanup_fractol(t_fractol *fractol)
{
	if (fractol->color_map)
		free(fractol->color_map);
	mlx_destroy_image(fractol->mlx_in, fractol->img.img);
	mlx_destroy_window(fractol->mlx_in, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx_in);
	free(fractol->mlx_in);
}

int	stop_handle(t_fractol *fractol)
{
	cleanup_fractol(fractol);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keycode, t_fractol *fractol)
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
		fractol->iteration_value += 200;
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
	{
		if (fractol->iteration_value > 200)
			fractol->iteration_value -= 200;
	}
	update_fractol_params(fractol);
	return (0);
}

int	button_handle(int button, int x, int y, t_fractol *fractol)
{
	double	old_zoom;
	double	mouse_re;
	double	mouse_im;

	mouse_re = (map_normalizer(x, -2, +2, WIDTH) * fractol->mult_zoom)
		+ fractol->shifting_x;
	mouse_im = (map_normalizer(y, +2, -2, HEIGHT) * fractol->mult_zoom)
		+ fractol->shifting_y;
	old_zoom = fractol->mult_zoom;
	if (button == Button5)
		fractol->mult_zoom *= 0.9;
	else if (button == Button4)
		fractol->mult_zoom *= 1.1;
	fractol->shifting_x = mouse_re - ((mouse_re - fractol->shifting_x)
			* fractol->mult_zoom / old_zoom);
	fractol->shifting_y = mouse_im - ((mouse_im - fractol->shifting_y)
			* fractol->mult_zoom / old_zoom);
	update_fractol_params(fractol);
	return (0);
}
