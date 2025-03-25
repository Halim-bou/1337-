/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:04:18 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 15:50:38 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0))
		|| (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0)))
	{
		fractol.name = av[1];
		if (ft_strncmp(av[1], "julia", 5) == 0)
			fractol.julia_params = &av[2];
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_in);
	}
	else
	{
		ft_putstr_fd("ERROR: ARGS: <julia> <n1> <n2> |or| <mandelbort>\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
