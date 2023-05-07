/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:58:47 by reira             #+#    #+#             */
/*   Updated: 2023/05/07 20:19:04 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 100
#define WIDTH 100
#define Y_START -2.0
#define Y_END 2.0
#define X_START -2.0
#define X_END 2.0
#define Y_SIZE (Y_END - Y_START)
#define X_SIZE (X_END - X_START)
#define CALC_LIMIT 100
#define ABS_SQUARE 4.0

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

int	main(void)
{
	int i;
	int j;
	double y_idx;
	double x_idx;
	t_complex z;
	i = 0;
	j = HEIGHT;
	z.re = 0.0;
	z.im = 0.0;
	while (j > 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			y_idx = Y_START + (j * (Y_SIZE / HEIGHT));
			x_idx = X_START + (i * (X_SIZE / WIDTH));
			i++;
		}
		j--;
	}
	return (0);
}