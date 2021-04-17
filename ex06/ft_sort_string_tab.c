/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:50:58 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 19:25:50 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (((int)(unsigned char)*s1) - ((int)(unsigned char)*s2));
}

void		ft_sort_string_arr(char **arr, unsigned int size)
{
	unsigned int	i;
	unsigned int	max_pos;
	char			*temp;

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

void		ft_sort_string_tab(char **tab)
{
	unsigned int size;

	size = 0;
	while (tab[size] != 0)
		++size;
	ft_sort_string_arr(tab, size);
}
