/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:55:40 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/18 18:59:32 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		ft_exit(&fractol->mlx);
	else if (keycode == XK_Up)
		fractol->center_y -= 0.1;
	else if (keycode == XK_Down)
		fractol->center_y += 0.1;
	else if (keycode == XK_Left)
		fractol->center_x -= 0.1;
	else if (keycode == XK_Right)
		fractol->center_x += 0.1 ;
	else if (keycode == 61)
		fractol->col.ran += 5;
	else if (keycode == XK_minus && fractol->col.ran > 1)
		fractol->col.ran -= 5;
	else if (keycode == 103)
	{
		if (fractol->gradient == 1)
			fractol->gradient = 0;
		else
			fractol->gradient = 1;
	}
	fractal_render(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	static int	lockpos;

	if (button == Button5)
		fractol->zoom *= 1.1;
	else if (button == Button4)
		fractol->zoom /= 1.1;
	else if (button == Button1)
	{
		if (lockpos)
			lockpos = 0;
		else
			lockpos = 1;
	}
	if (lockpos == 0)
	{
		fractol->center_x += (x - (double)fractol->width / 2)
			/ fractol->width * 0.1;
		fractol->center_y += (y - (double)fractol->height / 2)
			/ fractol->height * 0.1;
	}
	fractal_render(fractol);
	return (0);
}
