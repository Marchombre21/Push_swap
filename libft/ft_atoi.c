/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:22:34 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/14 14:07:57 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	const char	*truc;
// 	int	i;
// 	int	j;

// 	truc = "-15646786451645451564548461515646486515644665";
// 	i = ft_atoi(truc);
// 	j = atoi(truc);
// 	printf("%d\n", i);
// 	printf("%d\n", j);
// 	return (0);
// }
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] <= 57 && nptr[i] >= 48)
	{
		if ((result * 10 + nptr[i] - '0') / 10 != result)
			return (LONG_MAX * (sign > 0) + LONG_MIN * (sign < 0));
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
