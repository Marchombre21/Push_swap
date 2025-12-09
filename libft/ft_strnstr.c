/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:54:30 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/14 15:47:11 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptr;

// 	ptr = ft_strnstr("aaxx", "xx", 3);
// 	printf("%s\n", ptr);
// 	return (0);
// }

//Je ne vérifie pas !big ni !little car la fonction est censée crash dans 
//ce cas.
//Pas ouf l'utilisations de check_entries mais pas le choix rapport 
//au nombre de lignes.

static char	*check_entries(const char *big, const char *little, size_t len)
{
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (little[0] == '\0' || len == 0)
		return (check_entries(big, little, len));
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (little[j] && little[j] == big[k] && k < len)
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + k - j);
		}
		i++;
	}
	return (NULL);
}
