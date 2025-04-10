/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:04:18 by abelboua          #+#    #+#             */
/*   Updated: 2025/04/04 22:41:01 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/fractol.h"

int	check_args(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (((s[i] >= '0' && s[i] <= '9') || s[i] == '.') && dot < 2)
		{
			if (s[i] == '.')
				dot++;
			i++;
		}
		else
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol = (t_fractol){0};
	if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0))
		|| (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0)))
	{
		fractol.name = av[1];
		if (ft_strncmp(av[1], "julia", 5) == 0)
		{
			fractol.julia_params = &av[2];
			if (check_args(av[2]) == -1 || check_args(av[3]) == -1)
				return (ft_putstr_fd(ERROR_NUM, 2), EXIT_FAILURE);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_in);
	}
	else
		return (ft_putstr_fd(ERROR_ARGS, 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
