.PHONY: all clean fclean re

OBJECTS = main.o operators1.o operators2.o utils.o
NAME = do-op

all: $(NAME)

re: fclean all

clean:
	-rm -f $(OBJECTS)

fclean:
	-rm -f $(NAME) $(OBJECTS)

$(NAME): $(OBJECTS)
	gcc -Wall -Werror -Wextra $^ -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra $< -c -o $@
