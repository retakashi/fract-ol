/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:41:51 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 13:55:16 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_double(char **str, double *n)
{
	while (**str && ft_isdigit(**str))
	{
		*n = *n * 10.0 + **str - '0';
		*str += 1;
	}
}

static int	search_exponent(char **str, double *exp)
{
	size_t	i;
	double	n;
	int		neg;

	i = 0;
	n = 0.0;
	neg = 0;
	*exp = 0.0;
	while (**str && **str != '.' && **str != 'e' && **str != 'E')
	{
		i++;
		*str += 1;
	}
	if (!**str || **str == '.')
	{
		*str -= i;
		return (FALSE);
	}
	*str += 1;
	search_sign(str, &neg);
	change_double(str, &n);
	if (neg == 1)
		n *= -1;
	*exp = n;
	return (TRUE);
}

static void	add_demicals(char **str, double *n, double *m)
{
	double	i;

	*m = 0.0;
	i = 1.0;
	*str += 1;
	while (**str && ft_isdigit(**str))
	{
		*m = *m + 0.1 * (1.0 / i) * (**str - '0');
		i *= 10.0;
		*str += 1;
	}
	*n += *m;
}

static double	add_exponent(double n, double *exp, int *neg)
{
	if (*exp < 0)
	{
		while (*exp < 0)
		{
			n /= 10.0;
			*exp += 1;
		}
	}
	else if (*exp > 0)
	{
		while (*exp > 0)
		{
			n *= 10.0;
			*exp -= 1;
		}
	}
	if (*neg == 1)
		n *= -1;
	return (n);
}

double	ft_atof(char **str)
{
	double	n;
	double	m;
	int		neg;
	double	exp;

	neg = 0;
	n = 0.0;
	search_space(str);
	search_sign(str, &neg);
	change_double(str, &n);
	if (search_exponent(str, &exp) != FALSE)
		return (add_exponent(n, &exp, &neg));
	if (**str == '.')
		add_demicals(str, &n, &m);
	if (search_exponent(str, &exp) != FALSE)
		return (add_exponent(n, &exp, &neg));
	if (neg == 1)
		n *= -1;
	return (n);
}
