/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:36 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 12:51:47 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_DIGITS 32

int				ft_get_int_base(char *base)
{
	int offset;
	int offset_check;
	int int_base;

	offset = 0;
	while (base[offset] != '\0')
	{
		offset_check = 1;
		while (base[offset + offset_check] != '\0')
		{
			if (base[offset_check] == base[offset + offset_check])
				return (-1);
			offset_check++;
		}
		offset++;
	}
	int_base = 0;
	while (base[int_base] != '\0')
		int_base++;
	return (int_base >= 2 ? int_base : -1);
}

static char		*ft_nbr_string(int nb, int int_base, char *base, int digits)
{
	static char nbr_s[MAX_DIGITS];

	nb *= nb < 0 ? 1 : -1;
	while (digits--)
	{
		nbr_s[digits] = base[(nb % int_base) * -1];
		nb /= 10;
	}
	return (nbr_s);
}

void			ft_putnbr_base(int nb, char *base)
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
	nbr_s = ft_nbr_string(nb, int_base, base, digits);
	write(1, nbr_s, 32);
}
