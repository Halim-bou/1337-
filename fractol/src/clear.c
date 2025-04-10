/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:20:40 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 23:10:10 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	clear_fractol(t_fractol *fractol)
{
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx_in, fractol->img.img);
	if (fractol->mlx_win)
		mlx_destroy_window(fractol->mlx_in, fractol->mlx_win);
	if (fractol->mlx_in)
	{
		mlx_destroy_display(fractol->mlx_in);
		free(fractol->mlx_in);
	}
	mlx_allocation_error();
}

void	mlx_allocation_error(void)
{
	perror("Error: Problem with memory allocation!!\n");
	exit(EXIT_FAILURE);
}
