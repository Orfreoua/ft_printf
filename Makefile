CC = gcc
NAME = libftprintf.a
 SRC =	ft_printf.c \
 		ft_printf_utils.c \

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

clean: 
	rm -rf *.o

fclean: clean
	rm -rf libftprintf.a
re: fclean all