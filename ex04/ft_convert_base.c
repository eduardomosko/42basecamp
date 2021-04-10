/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:29:38 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 19:27:59 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if ((basen = ft_get_int_base(base)) == -1)
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
	if (ft_get_int_base(base_from) == -1 || ft_get_int_base(base_to) == -1)
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
