/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:38:50 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/13 18:42:04 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	char	*s;
// 	char	*ptr;

// 	s = "";
// 	ptr = ft_strrchr(s, 0);
// 	printf("%p\n", ptr);
// 	return (0);
// }

char	*ft_strrchr(const char *s, size_t c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
