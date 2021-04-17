#!/bin/sh

gcc -Wall -Wextra -Werror ft_putchar.c -c -o ft_putchar.o
gcc -Wall -Wextra -Werror ft_putstr.c -c -o ft_putstr.o
gcc -Wall -Wextra -Werror ft_strcmp.c -c -o ft_strcmp.o
gcc -Wall -Wextra -Werror ft_strlen.c -c -o ft_strlen.o
gcc -Wall -Wextra -Werror ft_swap.c -c -o ft_swap.o

ar rcs libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
