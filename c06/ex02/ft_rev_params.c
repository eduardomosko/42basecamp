/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:08 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 15:09:22 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	n;
	char			*str;

	while (--argc > 0)
	{
		n = 0;
		str = argv[argc];
		while (*str++ != '\0')
			++n;
		write(1, argv[argc], n);
		write(1, "\n", 1);
	}
}
