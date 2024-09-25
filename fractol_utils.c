/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:11:09 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 13:32:43 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex z, double x, double y)
{
	t_complex	ans;

	ans.re = z.re + x;
	ans.im = z.im + y;
	return (ans);
}

t_complex	complex_square(t_complex z)
{
	t_complex	ans;

	ans.re = (z.re * z.re) - (z.im * z.im);
	ans.im = 2.0 * z.re * z.im;
	return (ans);
}

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_color_gradient(t_data img, double t)
{
	int	r;
	int	g;
	int	b;

	r = (1 - t) * (img.color1 & RED) + t * (img.color2 & RED);
	g = (1 - t) * (img.color1 & GREEN) + t * (img.color2 & GREEN);
	b = (1 - t) * (img.color1 & BLUE) + t * (img.color2 & BLUE);
	return ((r & RED) | (g & GREEN) | (b & BLUE));
}

void	draw(t_data img)
{
	int		color;
	double	t;

	t = (double)1 / 20 * img.cnt;
	if (img.cnt >= CALC_LIMIT)
		color = 0x00000000;
	else if (img.cnt <= 20)
		color = get_color_gradient(img, t);
	else if (img.cnt > 20 && img.cnt <= 40)
		color = get_color_gradient(img, t - 1);
	else if (img.cnt > 40 && img.cnt <= 60)
		color = get_color_gradient(img, t - 2);
	else if (img.cnt > 60 && img.cnt <= 80)
		color = get_color_gradient(img, t - 3);
	else
		color = get_color_gradient(img, t - 4);
	put_pixel(&img, img.w_idx, img.h_idx, color);
}
