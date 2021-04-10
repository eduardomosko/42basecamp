/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:36 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 13:32:49 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_DIGITS 32

int				ft_get_int_base(char *base)
{
	int offset_check;
	int offset;

	offset = 0;
	while (base[offset] != '\0')
	{
		if (base[offset] == '-' || base[offset] == '+' ||
				(9 <= base[offset] && base[offset] <= 15)
				|| base[offset] == ' ')
			return (0);
		offset_check = 1;
		while (base[offset + offset_check] != '\0')
		{
			if (base[offset_check] == base[offset + offset_check])
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

	if ((nbr_s = malloc(digits + 1)) == 0)
		return (NULL);
	nbr_s[digits] = '\0';
	nb *= nb < 0 ? 1 : -1;
	while (digits--)
	{
		nbr_s[digits] = base[(nb % int_base) * -1];
		nb /= 10;
	}
	return (nbr_s);
}

char			*ft_itoa_base(int nb, char *base)
{
	int				digits;
	int				counter;
	int				int_base;
	char			*nbr_s;

	int_base = ft_get_int_base(base);
	if (int_base == -1)
		return ;
	digits = 1;
	counter = nb;
	while (counter /= int_base)
		digits++;
	return (ft_nbr_string(nb, int_base, base, digits));
}
