/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:36:14 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/18 20:33:10 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

void	assign_palette(t_fractol *fractol)
{
	fractol->col.palette[0] = 0xa99e93;
	fractol->col.palette[1] = 0x95847d;
	fractol->col.palette[2] = 0x8b7d7e;
	fractol->col.palette[3] = 0x89808f;
	fractol->col.palette[4] = 0x787695;
	fractol->col.palette[5] = 0x8089b8;
	fractol->col.palette[6] = 0x7ea1e3;
	fractol->col.palette[7] = 0x82b4f6;
	fractol->col.palette[8] = 0x86c5fe;
	fractol->col.palette[9] = 0x88d2f9;
	fractol->col.palette[10] = 0x93e4f3;
	fractol->col.palette[11] = 0x98eede;
	fractol->col.palette[12] = 0xa5facc;
	fractol->col.palette[13] = 0xacfbb0;
	fractol->col.palette[14] = 0xbafe9d;
	assign_palette2(fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->center_x = 0;
	fractol->center_y = 0;
	fractol->zoom = 1;
	fractol->height = 300;
	fractol->width = 300;
	fractol->mlx.img.img = mlx_new_image(fractol->mlx.mlx,
			fractol->width, fractol->height);
	fractol->mlx.img.addr = mlx_get_data_addr(fractol->mlx.img.img,
			&fractol->mlx.img.bits_per_pixel,
			&fractol->mlx.img.line_length, &fractol->mlx.img.endian);
	fractol->mlx.win = mlx_new_window(fractol->mlx.mlx,
			fractol->width, fractol->height, "Fractol");
	fractol->col.max_iter = 500;
	fractol->col.palet_size = 30;
	fractol->col.ran = 1;
	fractol->gradient = 1;
	assign_palette(fractol);
}

void	handle_param(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 4)
	{
		fractol->julia_x = ft_atod(argv[2]);
		fractol->julia_y = ft_atod(argv[3]);
	}
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractol->render = render_mandel;
	else if (argc == 2 && ft_strncmp(argv[1], "burningship", 11) == 0)
		fractol->render = render_ship;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		fractol->render = render_julia;
	else
	{
		errno = EINVAL;
		perror("Error");
		write(1, "Usage: ./fractol\n\
                 mandelbrot\n\
                 julia <val_c.r> <val_c.i>\n\
                 burningship\n", 117);
		exit(errno);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	handle_param(argc, argv, &fractol);
	fractol.mlx.mlx = mlx_init();
	fractol_init(&fractol);
	mlx_mouse_hook(fractol.mlx.win, mouse_hook, &fractol);
	mlx_hook(fractol.mlx.win, on_destroy, 0, ft_exit, &fractol.mlx);
	mlx_key_hook(fractol.mlx.win, key_hook, &fractol);
	fractal_render(&fractol);
	mlx_loop(fractol.mlx.mlx);
	return (0);
}
