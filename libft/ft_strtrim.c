/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:33:05 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/14 16:32:44 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_part_of(char const *set, char c)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		i;
	char	*new_str;
	int		k;

	if (!s1)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_part_of(set, s1[i]) == 1)
		i++;
	if (s1[i] != '\0')
		while (is_part_of(set, s1[j]) == 1)
			j--;
	new_str = ft_calloc(((j - i) + 2), sizeof(char));
	if (!new_str)
		return (NULL);
	while (i <= j)
	{
		new_str[k] = s1[i];
		k++;
		i++;
	}
	return (new_str);
}
