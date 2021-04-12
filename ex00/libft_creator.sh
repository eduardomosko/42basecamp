#!/bin/sh

gcc ft_putchar.c -c -o ft_putchar.o
gcc ft_putstr.c -c -o ft_putstr.o
gcc ft_strcmp.c -c -o ft_strcmp.o
gcc ft_strlen.c -c -o ft_strlen.o
gcc ft_swap.c -c -o ft_swap.o

ar rcs libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
