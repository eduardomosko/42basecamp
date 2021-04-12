.PHONY: clean all fclean re

objects=ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
files=libft.a $(objects)

all: libft.a

clean:
	-rm -f $(objects)

fclean:
	-rm -f $(files)

re: fclean all

libft.a: $(objects)
	ar rcs $@ $^

%.o: %.c
	gcc -Wall -Wextra -Werror $< -c -o $@

