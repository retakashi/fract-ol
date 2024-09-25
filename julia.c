/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:18:43 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 15:05:07 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_complex_argc3(t_data *img, t_complex *z)
{
	img->argc = 0;
	z->re = ft_atof(&img->argv[2]);
	img->tmp.re = z->re;
	if (z->re == INFINITY)
		put_error(4);
	z->im = ft_atof(&img->argv[2]);
	img->tmp.im = z->im;
	if (z->re == INFINITY)
		put_error(4);
	if (*img->argv[2] != '\0')
		put_error(3);
}

void	set_complex(t_data *img, t_complex *z)
{
	if (img->argc == 2)
	{
		img->argc = 0;
		search_space(&img->argv[1]);
		z->re = ft_atof(&img->argv[1]);
		img->tmp.re = z->re;
		if (z->re == INFINITY)
			put_error(4);
		z->im = ft_atof(&img->argv[1]);
		img->tmp.im = z->im;
		if (z->im == INFINITY)
			put_error(4);
		if (*img->argv[1] != '\0')
			put_error(3);
	}
	else if (img->argc == 3)
		set_complex_argc3(img, z);
	return ;
}

static void	get_julia_num(t_complex z, t_data *img)
{
	t_complex	ans;
	double		n;

	ans.re = img->x_idx;
	ans.im = img->y_idx;
	img->cnt = 0;
	n = 0.0;
	while (img->cnt < CALC_LIMIT)
	{
		ans = complex_square(ans);
		ans = complex_add(ans, z.re, z.im);
		n = (ans.re * ans.re) + (ans.im * ans.im);
		if (n > ABS_LIMIT)
			return ;
		img->cnt += 1;
	}
}

void	julia_error_check(int argc, char **argv)
{
	int	flg;

	flg = 0;
	if (argc == 2)
	{
		flg = 1;
		if (check_str(argv[1], "Julia", flg) == FALSE)
			put_error(3);
		while (*argv[1] != 'a')
			argv[1]++;
		argv[1]++;
		if (!*argv[1])
			put_error(3);
		search_space(&argv[1]);
		if (check_complex(argv[1]) == FALSE)
			put_error(3);
	}
	else
	{
		if (check_str(argv[1], "Julia", flg) == FALSE)
			put_error(2);
		if (check_complex(argv[2]) == FALSE)
			put_error(3);
	}
}

void	julia(t_data *img, t_complex z)
{
	img->y_size = img->y_end - img->y_start;
	img->x_size = img->x_end - img->x_start;
	img->h_idx = 0;
	z.re = img->tmp.re;
	z.im = img->tmp.im;
	while (img->h_idx < HEIGHT)
	{
		img->w_idx = 0;
		while (img->w_idx < WIDTH)
		{
			img->y_idx = img->y_start + (img->h_idx * (img->y_size / HEIGHT));
			img->x_idx = img->x_start + (img->w_idx * (img->x_size / WIDTH));
			get_julia_num(z, img);
			draw(*img);
			img->w_idx++;
		}
		img->h_idx++;
	}
}
