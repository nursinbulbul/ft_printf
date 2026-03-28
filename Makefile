NAME =	libftprintf.a

SRC	=	ft_printf.c \
		print_char.c \
		print_str.c \
		print_int.c \
		print_unsigned.c \
		print_hex.c \
		print_pointer.c \


OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re