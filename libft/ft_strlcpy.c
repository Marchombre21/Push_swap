/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:31:48 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 10:19:48 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <bsd/string.h>
// unsigned long	ft_strlcpy(char *dst, const char *src, size_t size);

// int	main(void)
// {
// 	char	str[75];
// 	char	str2[75];
// 	char	str3[75];
// 	char	str4[75];

// 	str3[0] = 'a';
// 	// str[8] = '\0';
// 	str4[0] = 'a';
// 	// str2[8] = '\0';
// 	printf("%zu\n", ft_strlcpy(str2, "coucou", 0));
// 	printf("%s\n", str2);
// 	printf("%zu\n", strlcpy(str, "coucou", 0));
// 	printf("%s\n", str);
// 	printf("%zu\n", strlcpy(str4, NULL, 3));
// 	printf("%s\n", str4);
// 	printf("%zu\n", ft_strlcpy(str3, NULL, 3));
// 	printf("%s\n", str3);
// 	return (0);
// }
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
