/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:38:35 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/18 20:35:05 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled / old_max + new_min);
}

void	assign_palette2(t_fractol *fractol)
{
	fractol->col.palette[15] = 0xbef385;
	fractol->col.palette[16] = 0xd0f182;
	fractol->col.palette[17] = 0xd0da77;
	fractol->col.palette[18] = 0xded083;
	fractol->col.palette[19] = 0xdcb487;
	fractol->col.palette[20] = 0xf8a3c4;
	fractol->col.palette[21] = 0xf2b2ab;
	fractol->col.palette[22] = 0xf991d8;
	fractol->col.palette[23] = 0xd6a8a1;
	fractol->col.palette[24] = 0xd0bc91;
	fractol->col.palette[25] = 0xc9d186;
	fractol->col.palette[26] = 0xafd270;
	fractol->col.palette[27] = 0xaee77c;
	fractol->col.palette[28] = 0x8deb91;
	fractol->col.palette[29] = 0x51bb8e;
}

int	gradient(int i, t_fractol *f, double x, double y)
{
	int		palette_index;
	double	t;

	if (i == f->col.max_iter)
		return (0x000055);
	t = (double)i / f->col.max_iter;
	if (f->gradient)
		return ((int)(9 * f->col.ran * (1 - t) * (t * t * t) * 255) << 16 |\
		(int)(15 * f->col.ran * ((1 - t) * (1 - t)) * (t * t) * 255) << 8 |\
		(int)(8.5 * f->col.ran * ((1 - t) * (1 - t) * (1 - t)) * t * 255));
	f->col.direction = atan2(y, x) / 2;
	f->col.shade = pow(sin(f->col.direction), 2);
	palette_index = (int)(t * f->col.ran * (f->col.palet_size
				- 1)) % f->col.palet_size;
	f->col.red = (f->col.palette[palette_index] >> 16) & 0xFF;
	f->col.green = (f->col.palette[palette_index] >> 8) & 0xFF;
	f->col.blue = f->col.palette[palette_index] & 0xFF;
	f->col.red *= f->col.shade;
	f->col.green *= f->col.shade;
	f->col.blue *= f->col.shade;
	f->col.red = 255 - f->col.red;
	f->col.green = 255 - f->col.green;
	f->col.blue = 255 - f->col.blue;
	return (f->col.red << 16
		| f->col.green << 8 | f->col.blue);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

double	ft_atod(const char *str)
{
	double	result;
	double	decimal_place;
	int		sign;
	int		i;

	i = 0;
	result = 0.0;
	decimal_place = 1.0;
	sign = 1;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal_place *= 0.1;
			result += (str[i++] - '0') * decimal_place;
		}
	}
	return (result * sign);
}
