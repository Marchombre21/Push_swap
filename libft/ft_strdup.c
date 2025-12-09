/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:23:41 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 08:44:30 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = NULL;

// 	printf("%s\n", strdup(s));
// 	printf("%s\n", ft_strdup(s));
// 	return (0);
// }

//On ne verifie pas si s = null, la vraie fonction ne le fait pas.
char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		new_str_len;
	int		i;

	i = 0;
	new_str_len = ft_strlen(s);
	new_str = malloc(sizeof(char) * new_str_len + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
