/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:36:12 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/25 17:34:41 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define Y_START -2.0
# define Y_END 2.0
# define X_START -2.0
# define X_END 2.0
# define HEIGHT 1000
# define WIDTH 1000
# define CALC_LIMIT 100
# define ABS_LIMIT 4.0
# define FALSE 0
# define TRUE 1
# define KEYDOWN 2
# define KEYUP 3
# define DESTROY 17
# define MOUSEUP 5
# define MOUSEDOWN 4
# define ESC_KEY 65307
# define G_KEY 103
# define B_KEY 98
# define MOUSEDOW 4
# define MOUSEUP 5

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define COLOR1 0x0000007D
# define COLOR2 0x00FFFFA1
# define COLOR3 0x00005000
# define ZOOM_LEN 0.2
# define ZOOM_LIMIT 0.3
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	int			argc;
	char		**argv;
	double		y_size;
	double		x_size;
	double		y_idx;
	double		x_idx;
	int			w_idx;
	int			h_idx;
	int			cnt;
	double		y_start;
	double		y_end;
	double		x_start;
	double		x_end;
	int			color1;
	int			color2;
	double		rate_x1;
	double		rate_x2;
	double		rate_y1;
	double		rate_y2;
	int			m;
	t_complex	tmp;
}				t_data;

//main.c
int				render_fractol(t_data *img);
//error_check.c
void			argc_error(int argc, char **argv, int *m);
int				check_str(char *str1, char *str2, int flg);
int				check_complex(char *str);
void			put_error(int error_flg);
//fractol_utils.c
t_complex		complex_add(t_complex z, double x, double y);
t_complex		complex_square(t_complex z);
void			draw(t_data img);
//ft_atoi.c
double			ft_atof(char **str);
//ft_atof_utils.c
void			search_space(char **str);
void			search_sign(char **str, int *neg);
//mandelbrot.c
void			mandelbrot(t_data *img);
//julia.c
void			set_complex(t_data *img, t_complex *z);
void			julia_error_check(int argc, char **argv);
void			julia(t_data *img, t_complex z);
//mlx_hook.c
int				check_hook(t_data *img);
//mlx_hook_utils.c
void			get_rate(int x, int y, t_data *img);
void			get_coordinate(int button, t_data *img);
//mandelbar.c
void			mandelbar(t_data *img);
#endif
