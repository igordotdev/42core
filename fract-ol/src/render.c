/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:41:12 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/18 20:30:31 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_mandel(t_fractol *fractol, int Px, int Py, int max_iter)
{
	double	x;
	double	xtemp;
	double	y;
	int		i;

	fractol->z.r = (scale(Px, -2.0, 0.47,
				fractol->width)) * fractol->zoom + fractol->center_x;
	fractol->z.i = (scale(Py, -1.12, 1.12,
				fractol->height)) * fractol->zoom + fractol->center_y;
	x = 0.0;
	y = 0.0;
	i = 0;
	while (x * x + y * y <= 4 && i < max_iter)
	{
		xtemp = ((x * x) - (y * y)) + fractol->z.r;
		y = (2 * x * y) + fractol->z.i;
		x = xtemp;
		i++;
	}
	pixel_put(&fractol->mlx.img, Px, Py, gradient(i, fractol, x, y));
	return (i);
}

int	render_julia(t_fractol *fractol, int Px, int Py, int max_iter)
{
	double	r;
	int		i;
	double	xtemp;

	r = 2;
	fractol->z.r = ((scale(Px, -r, r,
					fractol->width)) * fractol->zoom) + fractol->center_x;
	fractol->z.i = ((scale(Py, -r, r,
					fractol->height)) * fractol->zoom) + fractol->center_y;
	i = 0;
	while ((fractol->z.r * fractol->z.r)
		+ (fractol->z.i * fractol->z.i) < r * r && i < max_iter)
	{
		xtemp = (fractol->z.r * fractol->z.r)
			- (fractol->z.i * fractol->z.i) + fractol->julia_x;
		fractol->z.i = (2 * fractol->z.r * fractol->z.i) + fractol->julia_y;
		fractol->z.r = xtemp;
		i++;
	}
	pixel_put(&fractol->mlx.img, Px, Py,
		gradient(i, fractol, fractol->z.r, fractol->z.i));
	return (i);
}

int	render_ship(t_fractol *fractol, int Px, int Py, int max_iter)
{
	double	x;
	double	y;
	double	xtemp;
	int		i;

	fractol->z.r = (scale(Px, -2.5, 1.5,
				fractol->width)) * fractol->zoom + fractol->center_x;
	fractol->z.i = (scale(Py, -2.5, 1.5,
				fractol->height)) * fractol->zoom + fractol->center_y;
	x = 0.0;
	y = 0.0;
	i = 0;
	while (x * x + y * y < 4 && i < max_iter)
	{
		xtemp = fabs((x * x - y * y) + fractol->z.r);
		y = fabs((2 * x * y) + fractol->z.i);
		x = xtemp;
		i++;
	}
	pixel_put(&fractol->mlx.img, Px, Py, gradient(i, fractol, x, y));
	return (i);
}

int	fractal_render(t_fractol *fractol)
{
	int	px;
	int	py;
	int	i;

	py = 0;
	while (py < fractol->height)
	{
		px = 0;
		while (px < fractol->width)
		{
			i = fractol->render(fractol, px, py, fractol->col.max_iter);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win,
		fractol->mlx.img.img, 0, 0);
	return (0);
}
