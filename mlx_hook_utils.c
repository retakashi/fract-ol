/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:39:48 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/21 22:08:20 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_rate(int x, int y, t_data *img)
{
	img->rate_y1 = (double)y / HEIGHT;
	img->rate_y2 = 1.0 - img->rate_y1;
	img->rate_x1 = (double)x / WIDTH;
	img->rate_x2 = 1.0 - img->rate_x1;
	img->rate_y1 *= ZOOM_LEN;
	img->rate_y2 *= ZOOM_LEN;
	img->rate_x1 *= ZOOM_LEN;
	img->rate_x2 *= ZOOM_LEN;
}

void	get_coordinate(int button, t_data *img)
{
	if (button == 4)
	{
		img->y_start += img->rate_y1;
		img->y_end -= img->rate_y2;
		img->x_start += img->rate_x1;
		img->x_end -= img->rate_x2;
	}
	else if (button == 5)
	{
		img->y_start -= img->rate_y1;
		img->y_end += img->rate_y2;
		img->x_start -= img->rate_x1;
		img->x_end += img->rate_x2;
	}
}
