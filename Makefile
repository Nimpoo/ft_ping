CC:=gcc
CFLAGS:=-Werror -Wall -Wextra

NAME:=ft_ping

SRC:=$(addprefix src/, main.c)
OBJ:=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
