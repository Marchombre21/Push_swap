/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:19:47 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/15 12:51:07 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int	main(void)
// {
// 	char	**array = ft_split("\t\t\t\thello!\t\t\t\t", '\t');
// 	int	i = 0;

// 	printf("test of ft_split\n");
// 	while (array && array[i])
// 	{
// 		printf("La phrase est : %s\n", array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }

static void	add_word(int *index_words, int	*nb_words, int i, int j)
{
	index_words[j++] = i - 1;
	(*nb_words)++;
}

static void	free_array(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static void	ft_count_words(char const *s, char c, int *index_words,
	int	*nb_words)
{
	int	word;
	int	i;
	int	j;

	j = 0;
	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] == c && word)
		{
			(*nb_words)++;
			word = 0;
			index_words[j++] = i - 1;
		}
		else if (s[i] != c && !word)
		{
			word = 1;
			index_words[j++] = i;
		}
	}
	if (word)
		add_word(index_words, nb_words, i, j);
}

static char	**ft_fill_array(char **array, char const *s,
	int *index, int *nb_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < *nb_words)
	{
		array[i] = ft_calloc(((index[j + 1] - index[j] + 1) + 1), 1);
		if (!array[i])
		{
			free_array(array, i - 1);
			return (NULL);
		}
		k = 0;
		while (index[j] <= index[j + 1])
		{
			array[i][k] = s[index[j]];
			k++;
			index[j]++;
		}
		i++;
		j = j + 2;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		nb_words;
	int		*index_words;

	if (!s)
		return (NULL);
	nb_words = 0;
	index_words = malloc(sizeof(int) * ft_strlen(s));
	if (!index_words)
		return (NULL);
	ft_count_words(s, c, index_words, &nb_words);
	array = ft_calloc(nb_words + 1, sizeof(char *));
	if (!array)
	{
		free(index_words);
		return (NULL);
	}
	array = ft_fill_array(array, s, index_words, &nb_words);
	free(index_words);
	return (array);
}
// if (*s == '\0')
// 	{
// 		array = ft_calloc(1, sizeof(char *));
// 		if (!array)
// 			return (NULL);
// 		return (array);
// 	}