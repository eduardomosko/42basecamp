.PHONY: all clean fclean

objects = main.o
binary = ft_display_file

all: ft_display_file

clean:
	-rm -f $(objects)

fclean:
	-rm -f $(binary) $(objects)

ft_display_file: $(objects)
	gcc -Wall -Werror -Wextra $^ -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra $< -c -o $@
