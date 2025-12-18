/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:21:22 by bfitte            #+#    #+#             */
/*   Updated: 2025/12/17 12:08:12 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptr;
// 	char	s[] = "tripouille";

// 	printf("Pointeur du caractere recherché %p\n", s + 1);
// 	ptr = ft_strchr(s, 't' + 256);
// 	printf("%p\n", ptr);
// 	return (0);
// }

int	ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	s_len = ft_strlen(s);
	i = 0;
	while (i < (s_len + 1))
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
