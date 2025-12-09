/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:57:52 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/14 16:30:31 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	i;
	int	div;

	i = 1;
	div = 1;
	while (n / div > 9)
	{
		i++;
		div *= 10;
	}
	return (i);
}

static void	ft_fill_str(char *str, long nb, int nb_char)
{
	char	c;

	if (nb > 9)
	{
		c = (nb % 10) + 48;
		str[nb_char - 1] = c;
		ft_fill_str(str, nb / 10, nb_char - 1);
	}
	else
	{
		c = nb + 48;
		str[nb_char - 1] = c;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		nb_char;
	long	nb;

	nb = (long)n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	nb_char = ft_count(nb);
	str = malloc(sizeof(char) * (nb_char + sign) + 1);
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_fill_str(str, nb, nb_char + sign);
	str[nb_char + sign] = '\0';
	return (str);
}
