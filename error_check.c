/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:16:59 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/22 14:56:14 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	argv_error(int argc, char **argv, int *m)
{
	int	flg;

	if (argv[1][0] != 'M' && argv[1][0] != 'J')
		put_error(2);
	flg = 0;
	if (argv[1][0] == 'M')
	{
		if (argc != 2)
			put_error(1);
		if (check_str(argv[1], "Mandelbrot", flg) == FALSE && check_str(argv[1],
				"Mandelbar", flg) == FALSE)
			put_error(2);
		if (check_str(argv[1], "Mandelbrot", flg) == TRUE)
			*m = 1;
	}
	else
		julia_error_check(argc, argv);
}

void	argc_error(int argc, char **argv, int *m)
{
	if (argc < 2)
		put_error(2);
	if (argc > 3)
		put_error(1);
	else
		argv_error(argc, argv, m);
}

int	check_str(char *str1, char *str2, int flg)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str2);
	while (str1[i] && i < len)
	{
		if (!ft_strchr(&str1[i], str2[i]))
			return (FALSE);
		i++;
	}
	if (flg == 0 && str1[i])
		return (FALSE);
	if (flg == 1 && str1[i] != ' ' && check_complex(&str1[i]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_complex(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-'
			&& str[i] != 'e' && str[i] != '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	put_error(int error_flg)
{
	if (error_flg == 1)
		ft_putstr_fd("Too many arguments.\n", 2);
	if (error_flg == 2)
		ft_putstr_fd("Please enter \"Mandelbrot\" , \"Julia\"\
 or \"Mandelbar\".\n", 2);
	if (error_flg == 3)
		ft_putstr_fd(
			"Please enter the corrict complex number after \"Julia\".\n", 2);
	if (error_flg == 4)
		ft_putstr_fd("Too large complex.\n", 2);
	if (error_flg == 5)
		ft_putstr_fd("Failed to retrieve address\n", 2);
	exit(1);
}
