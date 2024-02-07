NAME    =	cub3D

CC      =	cc

CFLAGS =	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

OBJ_DIR     =	obj

FRAMEWORK = -framework OpenGL -framework AppKit

HEADERS     =	cub3D.h \
			cub3D_struct.h

SRCS    =	main.c \
			file_read.c \
			rgb_interpret.c \
			map_read.c \
			wall_set.c \
			minimap.c \
			minimap2.c \
			minimap_util.c \
			map_check.c \
			vector_init.c \
			movement1.c \
			movement2.c \
			init_mlx.c \
			raycast1.c \
			raycast2.c \
			utils1.c \
			utils2.c

MLX     =	mlx/libmlx.a
MLX_DIR     =	mlx

LIBFT     = libft/libft.a
LIBFT_DIR     =	libft/include

OBJS      =	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@echo "Compiled cub3D Successfully.."

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
all: $(NAME)

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C mlx
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRCS)
	@make norm -C libft
