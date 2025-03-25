/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:40:30 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 15:47:15 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	cleanup_fractol(t_fractol *fractol)
{
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
		fractol->iteration_value += 10;
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
	{
		if (fractol->iteration_value > 10)
			fractol->iteration_value -= 10;
	}
	fractol_render(fractol);
	return (0);
}

int	button_handle(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractol->mult_zoom *= 0.9;
	else if (button == Button5)
		fractol->mult_zoom *= 1.1;
	fractol_render(fractol);
	return (0);
}
