/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:38:33 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 02:43:14 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	char			*str;

	if (argc > 0)
	{
		n = 0;
		str = argv[0];
		while (*str++ != '\0')
			++n;
		write(1, argv[0], n);
		write(1, "\n", 1);
	}
}
