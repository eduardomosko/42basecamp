/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:50:58 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 19:26:27 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_string_arr(char **arr, unsigned int size,
		int (*cmp)(char*, char*))
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
			if (cmp(arr[i - 1], arr[i]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}
		--max_pos;
	}
}

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*))
{
	unsigned int size;

	size = 0;
	while (tab[size] != 0)
		++size;
	ft_sort_string_arr(tab, size, cmp);
}
