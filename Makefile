NAME = so_long

MK = make -s

MKD = mkdir

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -g -Lmlx -lmlx -framework OpenGL -framework Appkit 

HEADERS =	so_long.h \
		./get_next_line/get_next_line.h \
		mlx/mlx.h

INCLUDES =	mlx/libmlx.a

SRCs =	ft_read_map.c	\
		ft_check_map.c \
		ft_check.c \
		ft_draw.c \
		ft_finish.c \
		ft_functions.c \
		ft_move.c \
		get_next_line_utils.c \
		get_next_line.c	\
		so_long.c \

DIR_OBJs	= OBJECTS
OBJs = $(addprefix $(DIR_OBJs)/,$(SRCs:%.c=%.o))


vpath %.c sources get_next_line

all	:	make_lib make_dir $(NAME)

make_lib:
		$(MK) -C mlx

make_dir:
		$(MKD) -p $(DIR_OBJs)

$(DIR_OBJs)/%.o: %.c $(HEADERS) | make_dir
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJs) $(HEADERS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJs) $(INCLUDES) -o $(NAME)

clean	:
	$(MK) clean -C mlx
	$(RM) $(DIR_OBJs)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all