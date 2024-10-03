NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS = main.c fractol_utils.c mandelbrot.c julia.c ft_atof.c ft_atof_utils.c error_check.c mlx_hook.c mlx_hook_utils.c mandelbar.c
# MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
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

$(NAME): $(OBJS) $(LIBFT) ./minilibx-linux/libmlx_Darwin.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ./minilibx-linux/libmlx_Darwin.a $(MLX_FLAGS) -o $(NAME)

${OBJS_DIR}/%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

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
