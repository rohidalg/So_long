NAME = so_long
BNAME = so_long_bonus

MK = make -s
MKD = mkdir
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 
MLX_FLAGS = -g -Lminilibx-linux -lmlx_Linux -lX11 -lXext 

HEADERS = so_long.h \
          ./get_next_line/get_next_line.h \
          minilibx-linux/mlx.h

INCLUDES = minilibx-linux/libmlx.a

BSRCs = BSRCs/ft_read_map_bonus.c \
        BSRCs/ft_check_map_bonus.c \
        BSRCs/ft_check_bonus.c \
        BSRCs/ft_draw_bonus.c \
        BSRCs/ft_finish_bonus.c \
        BSRCs/ft_functions_bonus.c \
        BSRCs/ft_move_bonus.c \
        get_next_line_utils.c \
        get_next_line.c \
        BSRCs/so_long_bonus.c \
        BSRCs/ft_frame_bonus.c

SRCs = SRCs/ft_read_map.c \
       SRCs/ft_check_map.c \
       SRCs/ft_check.c \
       SRCs/ft_draw.c \
       SRCs/ft_finish.c \
       SRCs/ft_functions.c \
       SRCs/ft_move.c \
       get_next_line_utils.c \
       get_next_line.c \
       SRCs/so_long.c

DIR_OBJs = OBJECTS
DIR_BOBJs = BONUS_OBJECTS

OBJs = $(addprefix $(DIR_OBJs)/,$(notdir $(SRCs:.c=.o)))
BOBJs = $(addprefix $(DIR_BOBJs)/,$(notdir $(BSRCs:.c=.o)))

vpath %.c SRCs BSRCs get_next_line

all: make_lib make_dir $(NAME)

make_lib:
	$(MK) -C minilibx-linux

make_dir:
	$(MKD) -p $(DIR_OBJs)

$(DIR_OBJs)/%.o: %.c $(HEADERS) | make_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJs) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJs) $(INCLUDES) -o $(NAME) $(MLX_FLAGS)

bonus: make_lib make_Bdir $(BNAME)

make_Bdir:
	$(MKD) -p $(DIR_BOBJs)

$(DIR_BOBJs)/%.o: %.c $(HEADERS) | make_Bdir
	$(CC) $(CFLAGS) -c $< -o $@

$(BNAME): $(BOBJs) $(HEADERS)
	$(CC) $(CFLAGS) $(BOBJs) $(INCLUDES) -o $(BNAME) $(MLX_FLAGS)

clean:
	$(MK) clean -C minilibx-linux
	$(RM) $(DIR_BOBJs)
	$(RM) $(DIR_OBJs)

fclean: clean
	$(RM) $(BNAME)
	$(RM) $(NAME)

re: fclean all
