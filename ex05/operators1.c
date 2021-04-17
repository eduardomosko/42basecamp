/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:34:35 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 18:35:00 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_errno;

int	ft_sum(int a, int b)
{
	return (a + b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_div(int a, int b)
{
	if (b == 0)
	{
		g_errno = 1;
		return (0);
	}
	return (a / b);
}

int	ft_mod(int a, int b)
{
	if (b == 0)
	{
		g_errno = 2;
		return (0);
	}
	return (a % b);
}

int	ft_mult(int a, int b)
{
	return (a * b);
}
