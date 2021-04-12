/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:36 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/12 20:10:23 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_get_int_base(char *base)
{
	int offset_check;
	int offset;

	offset = 0;
	while (base[offset] != '\0')
	{
		if (base[offset] == '-' || base[offset] == '+' ||
				(9 <= base[offset] && base[offset] <= 15) ||
				base[offset] == ' ')
			return (0);
		offset_check = 1;
		while (base[offset + offset_check] != '\0')
		{
			if (base[offset] == base[offset + offset_check])
				return (-1);
			offset_check++;
		}
		offset++;
	}
	return (offset >= 2 ? offset : -1);
}

static char		*ft_nbr_string(int nb, int int_base, char *base, int digits)
{
	char	*nbr_s;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	nb *= -sign;
	digits += (sign < 0);
	if ((nbr_s = malloc(digits + 1)) == 0)
		return (NULL);
	nbr_s[digits] = '\0';
	while (digits--)
	{
		nbr_s[digits] = base[(nb % int_base) * -1];
		nb /= int_base;
	}
	if (sign < 0)
		nbr_s[0] = '-';
	return (nbr_s);
}

char			*ft_itoa_base(int nb, char *base)
{
	int				digits;
	int				counter;
	int				int_base;

	int_base = ft_get_int_base(base);
	if (int_base == -1)
		return (NULL);
	digits = 1;
	counter = nb;
	while (counter /= int_base)
		digits++;
	return (ft_nbr_string(nb, int_base, base, digits));
}
