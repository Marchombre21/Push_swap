/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:47:19 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/17 13:22:44 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	str[50] = "thanks to @apellicc for this test !\r\n";
// 	char	new_str2[50] = "thanks to @apellicc for this test !\r\n";

// 	printf("%s\n", (char *)memmove(str + 3, str, ft_strlen(str)));
// 	printf("%s\n", (char *)ft_memmove(new_str2 
// + 3, new_str2, ft_strlen(new_str2)));
// 	return (0);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*new_src;
	unsigned char		*new_dest;
	size_t				i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = -1;
	new_src = (const unsigned char *)src;
	new_dest = (unsigned char *)dest;
	if (new_dest < new_src)
	{
		while (++i < n)
			new_dest[i] = new_src[i];
	}
	else
	{
		while (n > 0)
		{
			new_dest[n - 1] = new_src[n - 1];
			n--;
		}
	}
	return (dest);
}
