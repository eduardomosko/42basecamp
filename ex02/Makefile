.PHONY: all clean fclean

objects = main.o errors.o files.o ft_string.o
binary = ft_tail

all: ft_tail

clean:
	-rm -f $(objects)

fclean:
	-rm -f $(binary) $(objects)

ft_tail: $(objects)
	gcc -Wall -Werror -Wextra $^ -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra $< -c -o $@
