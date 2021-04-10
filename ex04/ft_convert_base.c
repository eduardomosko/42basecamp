/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:29:38 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 12:49:42 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
			if (base[j++] == base[i])
				return (0);
		if (base[i] == '-' || base[i] == '+' ||
				(9 <= base[i] && base[i] <= 15) || base[i] == ' ')
			return (0);
		++i;
	}
	return (i);
}

int					findchar(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (c == str[i])
			return (i);
	return (-1);
}

int					ft_atoi_base(char *str, char *base)
{
	unsigned int	basen;
	int				offset;
	int				sign;
	int				num;

	if ((basen = check_base(base)) < 2)
		return (0);
	while ((9 <= *str && *str <= 15) || *str == ' ')
		++str;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	num = 0;
	while ((offset = findchar(*str, base)) >= 0)
	{
		num *= basen;
		num += sign * offset;
		++str;
	}
	return (num);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
}
