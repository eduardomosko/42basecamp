.PHONY: all clean fclean

OBJECTS = main.o errors.o files.o ft_string.o buffer.o arg_parse.o ascii_format.o default_format.o
NAME = ft_hexdump

all: $(NAME)

clean:
	-rm -f $(OBJECTS)

fclean:
	-rm -f $(NAME) $(OBJECTS)

$(NAME): $(OBJECTS)
	gcc -Wall -Werror -Wextra $^ -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra $< -c -o $@
