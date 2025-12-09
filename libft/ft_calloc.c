/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:10:20 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 12:15:09 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int     size = 8539;

// 			void * d1 = ft_calloc(size, sizeof(int));
// 			void * d2 = calloc(size, sizeof(int));
// 			// if (memcmp(d1, d2, size * sizeof(int)) == 0)
// 			// 	printf("youhou");
// 			free(d1);
// 			free(d2);
// 	return (0);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!nmemb || !size)
	{
		array = malloc(sizeof(char));
		if (!array)
			return (NULL);
		ft_memset(array, 0, 1);
		return (array);
	}
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	else
	{
		array = malloc(nmemb * size);
		if (!array)
			return (NULL);
		ft_memset(array, 0, (size * nmemb));
		return (array);
	}
}
