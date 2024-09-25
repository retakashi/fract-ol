/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:08:31 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 13:29:26 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_mandelbrot_num(t_complex z, t_data *img)
{
	double	ans;

	ans = 0;
	img->cnt = 0;
	while (img->cnt < CALC_LIMIT)
	{
		z = complex_square(z);
		z = complex_add(z, img->x_idx, img->y_idx);
		ans = (z.re * z.re) + (z.im * z.im);
		if (ans > ABS_LIMIT)
			return ;
		img->cnt += 1;
	}
}

void	mandelbrot(t_data *img)
{
	t_complex	z;

	z.re = 0.0;
	z.im = 0.0;
	img->h_idx = 0;
	img->y_size = img->y_end - img->y_start;
	img->x_size = img->x_end - img->x_start;
	while (img->h_idx < HEIGHT)
	{
		img->w_idx = 0;
		while (img->w_idx < WIDTH)
		{
			img->y_idx = img->y_start + (img->h_idx * (img->y_size / HEIGHT));
			img->x_idx = img->x_start + (img->w_idx * (img->x_size / WIDTH));
			get_mandelbrot_num(z, img);
			draw(*img);
			img->w_idx++;
		}
		img->h_idx++;
	}
}
