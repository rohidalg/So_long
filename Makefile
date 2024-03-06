NAME = so_long

HEADERS =	so_long.h \
		./get_next_line/get_next_line.h \
		mlx/mlx.h

INCLUDES =	mlx/libmlx.a

SOURCES =	ft_read_map.c	\
		ft_check_map.c \
		ft_draw.c \
		ft_finish.c \
		ft_functions.c \
		ft_move.c \
		get_next_line_utils.c \
		get_next_line.c	\


DIR_OBJ	= objects
OBJECTS = $(addprefix $(DIR_OBJ)/,$(SOURCES:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -g -Lmlx -lmlx -framework OpenGL -framework Appkit


vpath %.c sources get_next_line

all	:	make_lib make_dir $(NAME)

make_lib:
		@make -C mlx
		@echo "\n\n minilibx complete!\n\n"

make_dir:
		@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.c $(HEADERS) | make_dir
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJECTS) $(HEADERS)
	@echo "Compiling so long"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)
	@echo "Done!"

clean	:
	@echo "Removing (so_long) objects..."
	@make clean -C mlx
	@rm -rf $(DIR_OBJ)
	@echo "Done!"

fclean	:	clean
	@echo "Removing execute (so_long)..."
	@rm -rf $(NAME)
	@echo "Done!"

re	:	fclean all