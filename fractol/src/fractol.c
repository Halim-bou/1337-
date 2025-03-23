/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:04:18 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 18:04:54 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/fractol.h"

void	init_color_map(t_fractol *fractol)
{
	int	i;

	if (fractol->color_map)
		free(fractol->color_map);
	fractol->color_map = malloc(sizeof(int) * (fractol->iteration_value + 1));
	if (!fractol->color_map)
		mlx_allocation_error();
	i = 0;
	while (i <= fractol->iteration_value)
	{
		fractol->color_map[i] = map_normalizer(i, BLACK, WHITE,
				fractol->iteration_value);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) != 0))
		|| (ac == 4 && (ft_strncmp(av[1], "julia", 5) != 0))
		|| (ac == 1))
	{
		ft_putstr_fd("ERROR: ARGS: <julia> <n1> <n2> /or/ <mandlbort>\n", 2);
		return (EXIT_FAILURE);
	}
	fractol.name = av[1];
	fractol.color_map = NULL;
	if (ft_strncmp(av[1], "julia", 5) == 0)
		fractol.julia_params = &av[2];
	fractol_init(&fractol);
	fractol_render(&fractol);
	mlx_loop(fractol.mlx_in);
	return (EXIT_SUCCESS);
}
