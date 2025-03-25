/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:43:25 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 03:16:06 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->v_escape = 4;
	fractol->iteration_value = 50;
	fractol->shifting_x = 0.0;
	fractol->shifting_y = 0.0;
	fractol->mult_zoom = 1.0;
	fractol->color = 0xFF0000;
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		fractol->julia_x = atof(fractol->julia_params[0]);
		fractol->julia_y = atof(fractol->julia_params[1]);
	}
}

void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win,
		KeyPress,
		KeyPressMask,
		key_handle,
		fractol);
	mlx_hook(fractol->mlx_win,
		ButtonPress,
		ButtonPressMask,
		button_handle,
		fractol);
	mlx_hook(fractol->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		stop_handle,
		fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_in = mlx_init();
	if (fractol->mlx_in == NULL)
		mlx_allocation_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx_in, WIDTH,
			HEIGHT, fractol->name);
	if (fractol->mlx_win == NULL)
		clear_fractol(fractol);
	fractol->img.img = mlx_new_image(fractol->mlx_in,
			WIDTH, HEIGHT);
	if (fractol->img.img == NULL)
		clear_fractol(fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	if (fractol->img.addr == NULL)
		clear_fractol(fractol);
	event_init(fractol);
	data_init(fractol);
}
