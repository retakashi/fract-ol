/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:36:02 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/21 22:11:47 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_mandelbar_num(t_complex z, t_data *img)
{
	double		ans;
	t_complex	n;

	ans = 0;
	img->cnt = 0;
	n.re = 0;
	n.im = 0;
	while (img->cnt < CALC_LIMIT)
	{
		n.re = (z.re * z.re) - (z.im * z.im) + img->x_idx;
		n.im = -2 * z.re * z.im + img->y_idx;
		z.re = n.re;
		z.im = n.im;
		ans = (n.re * n.re) + (n.im * n.im);
		if (ans > ABS_LIMIT)
			return ;
		img->cnt += 1;
	}
}

void	mandelbar(t_data *img)
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
			get_mandelbar_num(z, img);
			draw(*img);
			img->w_idx++;
		}
		img->h_idx++;
	}
}
