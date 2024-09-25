# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:49:43 by rtakashi          #+#    #+#              #
#    Updated: 2023/05/22 13:24:17 by rtakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS = main.c fractol_utils.c mandelbrot.c julia.c ft_atof.c ft_atof_utils.c error_check.c mlx_hook.c mlx_hook_utils.c mandelbar.c
MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit
OBJS = ${addprefix $(OBJS_DIR)/,$(SRCS:.c=.o)}
OBJS_DIR = objs

# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# ifdef WITH_BONUS
# OBJS += $(BONUS_OBJS)
# endif
# AR = ar
# ARFLAGS = rcs
RM = rm -f

.DEFAULT_GOAL :=$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

${OBJS_DIR}/%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean: 
	make clean -C libft
	$(RM) $(OBJS) 
# $(BONUS_OBJS)


fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

# bonus: 
# 	@make WITH_BONUS=1	

.PHONY: all clean fclean re
