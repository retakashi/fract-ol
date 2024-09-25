/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:33:57 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 13:54:16 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	search_space(char **str)
{
	while (**str && ((**str >= 9 && **str <= 13) || **str == 32))
		*str += 1;
}

void	search_sign(char **str, int *neg)
{
	if (**str == '-')
	{
		*neg = 1;
		*str += 1;
	}
	else if (**str == '+')
		*str += 1;
}
