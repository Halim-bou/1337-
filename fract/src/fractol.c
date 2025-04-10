/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:59:22 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/21 06:59:02 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Fractol
 * julia and mandelbrot
 * able to take command line args to disipline which fractal to render
 * able to take command line args to shape Julia, x y coordinates
 * ESC closes the process with no leaks
 * Click on the X window, closes the process leaks free
 */
#include "../headers/fractol.h"

int main(int ac, char **av)
{
    t_fractol fractol;

    if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) != 0))
        || (ac == 4 && (ft_strncmp(av[1], "julia", 5) != 0))
        || (ac == 1))
    {
        ft_putstr_fd("ERROR: ARGS: <julia> <n1> <n2> /or/ <mandlbort>\n", 2);
        return (EXIT_FAILURE);
    }

    /* Initialize basic data */
    fractol.name = av[1];
    fractol.color_map = NULL;

    /* Store Julia parameters if applicable */
    if (ft_strncmp(av[1], "julia", 5) == 0)
    {
        fractol.julia_params = &av[2];
    }

    /* Initialize fractol and render */
    fractol_init(&fractol);
    fractol_render(&fractol);

    /* Enter main loop */
    mlx_loop(fractol.mlx_in);

    return (EXIT_SUCCESS);
}
