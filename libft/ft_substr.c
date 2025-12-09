/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:45:05 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 12:08:33 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	char	*new_str;

// 	new_str = ft_substr("", 1, 1);
// 	printf("%s\n", new_str);
// 	free(new_str);
// 	return (0);
// }

static int	ft_size_malloc(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s_len == 0 && start != 0)
		return (0);
	else if ((s_len - 1) < start)
		return (0);
	else if ((s_len - start) <= (unsigned int)len)
		return (s_len - start);
	else if ((s_len - start) > (unsigned int)len)
		return (len);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	int		size_malloc;

	if (!s)
		return (NULL);
	size_malloc = ft_size_malloc(s, start, len);
	i = 0;
	new_str = malloc(sizeof(char) * size_malloc + 1);
	if (!new_str)
		return (NULL);
	if (s[i] != '\0' && size_malloc != 0)
	{
		while (i < len && s[start])
			new_str[i++] = s[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}
