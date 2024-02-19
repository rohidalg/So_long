NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCs = \

OBJs = $(SRCs:.c=.o)

all : $(NAME)

# $(NAME) : $(OBJs)
# 	ar rcs $(NAME) $(OBJs)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean : 
	$(RM) $(OBJs) 


fclean : clean 
	$(RM) $(NAME)


re : fclean all
