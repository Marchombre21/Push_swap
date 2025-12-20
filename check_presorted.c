/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_presorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:58:32 by gmach             #+#    #+#             */
/*   Updated: 2025/12/20 12:21:49 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*is_next_in_lists(int value, char **lists, int max_size)
{
	int		i;
	int		j;
	char	*i_lists;
	int		end;

	i = 0;
	j = 0;
	i_lists = malloc(sizeof(char) * max_size + 1);
	if (!i_lists)
		return (NULL);
	while (lists[i])
	{
		end = ft_strlen(lists[i]);
		if (ft_atoi(&lists[i][end]) < value)
			i_lists[j++] = i;
		i++;
	}
	i_lists[j] = '\0';
	return (i_lists);
}

static t_stack	*new_list(int value, int min, char **lists, int max_size)
{
	int	i;

	i = 0;
	while (lists[i])
		i++;
	lists[i] = malloc(sizeof(char) * max_size + 1);
	if (!lists[i])
		return (NULL);
	lists[i][0] = ft_itoa(value);
	lists[i][1] = '\0';
	return (0);
}

static void	add_to_lists(int value, char *i_lists, char **lists)
{
	int	i;
	int	end;

	i = 0;
	while (i_lists[i])
	{
		end = strlen(lists[i_lists[i]]);
		lists[i_lists[i]][end] = ft_itoa(value);
		lists[i_lists[i]][end + 1] = '\0';
		i++;
	}
}

static t_stack	*best_list(char **lists)
{
	int	i;
	int	j;
	int	max;
	int	best_i;

	i = 0;
	max = 0;
	best_i = 0;
	while (lists[i])
	{
		j = 0;
		while (lists[i][j])
			j++;
		if (j > max)
		{
			max = j;
			best_i = i;
		}
		i++;
	}
	return (lists[best_i]);
}

t_stack	*pre_sorted_list(t_stacks *stacks, int min)
{
	t_stack	*cur;
	t_stack	**lists;
	t_stack	*i_lists;
	int		max_size;

	lists = malloc(sizeof(char *) * (max_size + 1));
	if (!lists)
		return (NULL);
	cur = &stacks->stack_a;
	while (cur->value != min && cur)
		cur = cur->next;
	cur = cur->next;
	while (cur->value != min)
	{
		i_lists = is_next_in_lists(cur->value, lists);
		if (i_lists == -1)
			if(new_list(cur->value, min, lists) == -1)
				exit_error(stacks);
		else
			add_to_lists(cur->value, i_lists, lists);
		if (cur->next)
			cur = cur->next;
		else
			cur = &stacks->stack_a;
	}
	return (best_list(lists));
}
