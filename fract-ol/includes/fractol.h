/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:38:02 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/18 20:30:08 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_color
{
	int			ran;
	int			red;
	int			green;
	int			blue;
	int			max_iter;
	double		t;
	double		shade;
	double		direction;
	int			palet_size;
	int			palette[30];
}				t_color;

typedef struct s_mlx
{
	t_img	img;
	void	*mlx;
	void	*win;

}				t_mlx;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_fractol
{
	int				(*render)(struct s_fractol
			*fractol, int Px, int Py, int max_iter);
	double			center_x;
	double			center_y;
	double			zoom;
	int				height;
	int				width;
	t_mlx			mlx;
	t_complex		z;
	double			julia_x;
	double			julia_y;
	t_color			col;
	int				gradient;
}				t_fractol;

enum
{
	on_destroy = 17
};

int				fractal_render(t_fractol *fractol);
double			scale(double unscaled, double new_min,
					double new_max, double old_max);
int				gradient(int i, t_fractol *fractol, double x, double y);
int				key_hook(int keycode, t_fractol *fractol);
int				mouse_hook(int button, int x, int y, t_fractol *fractol);
int				ft_exit(t_mlx *mlx);
void			fractol_init(t_fractol *fractol);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atod(const char *str);
int				render_julia(t_fractol *fractol, int Px, int Py, int max_iter);
int				render_mandel(t_fractol *fractol, int Px, int Py, int max_iter);
int				render_ship(t_fractol *fractol, int Px, int Py, int max_iter);
void			assign_palette2(t_fractol *fractol);

#endif