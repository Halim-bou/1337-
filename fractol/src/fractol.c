/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:59:22 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/18 07:02:52 by abelboua         ###   ########.fr       */
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
	t_fractol	fractol;
	if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot",10) != 0))
		|| (ac == 4 && (ft_strncmp(av[1], "julia", 5) != 0))
		|| (ac == 1))
	{
		ft_putstr_fd("ERROR: ARGS: <julia> <n1> <n2> /or/ <mandlbort>\n", 2);
		return (EXIT_FAILURE);
	}
	fractol.name = av[1];
	fractol_init(&fractol);
	fractol_render(&fractol);
	mlx_loop(fractol.mlx_in);
	return (EXIT_SUCCESS);
}
