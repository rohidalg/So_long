NAME = so_long.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCs = ft_read_map.c \
	

OBJs = $(SRCs:.c=.o)

all : $(NAME)

$(NAME) : $(OBJs)
	ar rcs $(NAME) $(OBJs)

clean : 
	$(RM) $(OBJs) 


fclean : clean 
	$(RM) $(NAME)


re : fclean all
