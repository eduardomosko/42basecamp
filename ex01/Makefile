.PHONY: all clean fclean

objects = main.o errors.o files.o
binary = ft_cat

all: ft_cat

clean:
	-rm -f $(objects)

fclean:
	-rm -f $(binary) $(objects)

ft_cat: $(objects)
	gcc -Wall -Werror -Wextra $^ -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra $< -c -o $@
