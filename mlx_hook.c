/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:07:41 by rtakashi          #+#    #+#             */
/*   Updated: 2024/10/03 11:49:55 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move_key(int keycode, t_data *img)
{
	if (keycode == LEFT)
	{
		img->x_start -= 0.1;
		img->x_end -= 0.1;
		render_fractol(img);
	}
	else if (keycode == RIGHT)
	{
		img->x_start += 0.1;
		img->x_end += 0.1;
		render_fractol(img);
	}
	else if (keycode == UP)
	{
		img->y_start -= 0.1;
		img->y_end -= 0.1;
		render_fractol(img);
	}
	else if (keycode == DOWN)
	{
		img->y_start += 0.1;
		img->y_end += 0.1;
		render_fractol(img);
	}
	return (0);
}

static int	close_key(int keycode, t_data *img)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	else if (keycode == G_KEY)
	{
		img->color1 = COLOR3;
		render_fractol(img);
	}
	else if (keycode == B_KEY)
	{
		img->color1 = COLOR1;
		render_fractol(img);
	}
	else
		move_key(keycode, img);
	return (0);
}

static int	close_destroy(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}

static int	mouse_hook(int button, int x, int y, t_data *img)
{
	get_rate(x, y, img);
	if (button == MOUSEDOWN && img->y_end - img->y_start > ZOOM_LIMIT && img->x_end
		- img->x_start > ZOOM_LIMIT)
	{
		get_coordinate(button, img);
		render_fractol(img);
	}
	else if (button == MOUSEUP)
	{
		get_coordinate(button, img);
		render_fractol(img);
	}
	return (0);
}

int	check_hook(t_data *img)
{
	mlx_hook(img->mlx_win, KEYDOWN, 1L<<0, close_key, img);
	mlx_hook(img->mlx_win, DESTROY, 1L<<0, close_destroy, img);
	mlx_hook(img->mlx_win, MOUSEUP, 1L<<6, mouse_hook, img);
	mlx_hook(img->mlx_win, MOUSEDOWN, 1L<<6, mouse_hook, img);
	return (0);
}
