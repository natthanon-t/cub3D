NAME    =	cub3D

CC      =	cc

CFLAGS =	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

FRAMEWORK = -framework OpenGL -framework AppKit

HEADERS     =	cub3D_struct.h \
				cub3D.h \
				mlx.h

SRCS    =	main.c

MLX	=	mlx/libmlx.a
MLX_DIR	=	mlx/

LIBFT	= libft/libft.a
LIBFT_DIR	=	libft/include

OBJS    =	$(SRCS:.c=.o)

$(NAME):
	@$(MAKE) -C libft
	@$(MAKE) -C mlx
	@$(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(SRCS) $(FRAMEWORK) -o $(NAME)

$(OBJS): $(HEADERS)

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C mlx
	@$(RM) $(LIBFT) $(MLX) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(SRCS)
	@make norm -C libft
