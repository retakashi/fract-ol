/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:41:37 by reira             #+#    #+#             */
/*   Updated: 2023/05/08 02:09:31 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

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

int	ft_isdigit(int c)
{
	return ('0' <= c && '9' >= c);
}

void	search_exponent(char **str, int *exp)
{
	int	i;
	int	n;
	int	neg;

	i = 0;
	*exp = 0;
	neg = 0;
	while (**str && **str != '.' && **str != 'e' && **str != 'E')
	{
		i++;
		*str += 1;
	}
	if (!**str)
		*str -= i;
	else if (**str == '.')
		*str -= i;
	else if (**str == 'e' || **str == 'E')
	{
		n = 0;
		*str += 1;
		search_sign(str, &neg);
		while (ft_isdigit(**str))
		{
			n = n * 10 + **str - '0';
			*str += 1;
		}
		if (neg == 1)
			n *= -1;
		*exp = n;
	}
}

void	demicals(char **str, double *n)
{
	double	i;

	*n = 0.0;
	i = 1.0;
	while (**str && ft_isdigit(**str))
	{
		*n = *n + 0.1 * (1.0 / i) * (**str - '0');
		i *= 10.0;
		*str += 1;
	}
}

double	add_exponent(double n, int *exp, int *neg)
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

double	ft_atof(char *str)
{
	double	n;
	double	m;
	int		neg;
	int		exp;

	neg = 0;
	n = 0.0;
	search_sign(&str, &neg);
	while (str && ft_isdigit(*str))
	{
		n = n * 10.0 + *str - '0';
		str++;
	}
	search_exponent(&str, &exp);
	if (exp != 0)
		return (add_exponent(n, &exp, &neg));
	if (*str == '.')
	{
		str++;
		demicals(&str, &m);
		n += m;
	}
    search_exponent(&str, &exp);
	if (exp != 0)
		return (add_exponent(n, &exp, &neg));
	if (neg == 1)
		n *= -1;
	return (n);
}

int	main(void)
{
	double max = DBL_MAX;
	char *str = "-1.7976931348623157e+308";
	double n;
	// n=ft_atof(str);
	n = atof(str);
	printf("n %e\n", n);
	n = ft_atof(str);
	printf("ft %e\n", n);
	// printf("double_max %e\n", max / 10);
	// printf("double_min %f\n", max);
	return (0);
}