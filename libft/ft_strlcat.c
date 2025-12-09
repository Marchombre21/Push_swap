/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:57:09 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 10:23:31 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <bsd/string.h>
// unsigned long	ft_strlcat(char *dst, const char *src, size_t size);

// int	main(void)
// {
	// char	str[75];
	// char	str2[75];
	// char	str3[75];
	// char	str4[75];

	// str3[0] = 'a';
	// str3[8] = '\0';
	// str4[0] = 'a';
	// str4[8] = '\0';
	// printf("%zu\n", ft_strlcat(str4, "coucou", 3));
	// printf("%zu\n", strlcat(str3, "coucou", 3));
	// printf("%zu\n", ft_strlcat(str3, "coucou", 3));
	// printf("%zu\n", strlcat(str4, "coucou", 3));
	// printf("%s\n", str4);
	// printf("%s\n", str3);
	// printf("%s\n", str3);
	// printf("%s\n", str4);
// 	return (0);
// }
//Ancienne version je la garde au cas où.
// j = 0;
// i = dest_len;
// while (src[j] && j < (size - dest_len - 1))
// {
// 	dst[i] = src[j];
// 	i++;
// 	j++;
// }
// dst[i] = '\0';

//Pas de verif de null, ca doit crash si c'est le cas.

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = 0;
	while (dest_len < size && dst[dest_len])
		dest_len++;
	if (size == dest_len)
		return (src_len + size);
	if (src_len < size - dest_len)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
