/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:48:25 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 14:51:26 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	int				i;
	char			*str;

	i = 0;
	while (++i < argc)
	{
		n = 0;
		str = argv[i];
		while (*str++ != '\0')
			++n;
		write(1, argv[i], n);
		write(1, "\n", 1);
	}
}
