/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:06 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/09 04:21:49 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (((int)(unsigned char)*s1) - ((int)(unsigned char)*s2));
}

void		ft_sort_string_arr(char **arr, int size)
{
	int		max_pos;
	int		i;
	char	*temp;

	max_pos = size;
	while (max_pos > 0)
	{
		i = 0;
		while (++i < max_pos)
		{
			if (ft_strcmp(arr[i - 1], arr[i]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}
		--max_pos;
	}
}

int			main(int argc, char *argv[])
{
	unsigned int	n;
	int				i;
	char			*str;

	i = 0;
	ft_sort_string_arr(argv + 1, argc - 1);
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
