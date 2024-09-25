/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:28:13 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 15:21:21 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_fractol(t_data *img)
{
	t_complex	z;

	if (img->argv[1][0] == 'M' && img->m == 1)
		mandelbrot(img);
	else if (img->argv[1][0] == 'M' && img->m == 0)
		mandelbar(img);
	else
	{
		set_complex(img, &z);
		julia(img, z);
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

static void	set_t_data(int argc, char **argv, t_data *img)
{
	img->argc = argc;
	img->argv = argv;
	img->y_start = Y_START;
	img->y_end = Y_END;
	img->x_start = X_START;
	img->x_end = X_END;
	img->color1 = COLOR1;
	img->color2 = COLOR2;
}

static void	fractal_init(int argc, char **argv, t_data *img)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		put_error(5);
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Hello world!");
	if (img->mlx_win == NULL)
		put_error(5);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		put_error(5);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
		put_error(5);
	set_t_data(argc, argv, img);
	render_fractol(img);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fractol");
// }

int	main(int argc, char **argv)
{
	t_data	img;
	int		m;

	m = 0;
	argc_error(argc, argv, &m);
	img.m = m;
	fractal_init(argc, argv, &img);
	check_hook(&img);
	mlx_loop(img.mlx);
	return (0);
}
