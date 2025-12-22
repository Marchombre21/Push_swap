/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_presorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:58:32 by gmach             #+#    #+#             */
/*   Updated: 2025/12/22 11:55:01 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*find_valid_lists(int value, t_lists *sorted)
{
	int		i;
	t_stack	*cur;
	t_stack	*new_node;

	i = 0;
	sorted->i_lists = NULL;
	while (i < sorted->list_count && sorted->lists[i])
	{
		cur = sorted->lists[i];
		while (cur && cur->next)
			cur = cur->next;
		if (cur && cur->value < value)
		{
			new_node = ft_lstnew(i);
			if (!new_node)
			{
				ft_lstclear(&sorted->i_lists);
				return (NULL);
			}
			ft_lstadd_back(&sorted->i_lists, new_node);
		}
		i++;
	}
	return (sorted->i_lists);
}

static void	add_to_lists(int value, t_lists *sorted)
{
	t_stack	*cur;
	t_stack	*new_node;

	cur = sorted->i_lists;
	while (cur)
	{
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			ft_lstclear(&sorted->i_lists);
			free_all_lists(sorted);
			exit_error(sorted->stacks);
		}
		ft_lstadd_back(&sorted->lists[cur->value], new_node);
		cur = cur->next;
	}
	ft_lstclear(&sorted->i_lists);
}

static t_stack	*find_best_list(t_stack **lists, int list_count)
{
	int		i;
	int		size;
	int		best_size;
	int		best_index;

	i = 0;
	best_size = 0;
	best_index = 0;
	while (lists[i] && i < list_count)
	{
		size = ft_lstsize((t_stack *)lists[i]);
		if (size > best_size)
		{
			best_size = size;
			best_index = i;
		}
		i++;
	}
	i = -1;
	while (lists[++i])
		if (i != best_index)
			ft_lstclear(&lists[i]);
	return (lists[best_index]);
}

static t_stack	*handlst(int min, t_stack *cur, t_lists *sorted)
{
	int		*count;
	t_stack	*best_list;

	count = &sorted->list_count;
	*count = 0;
	while (cur->value != min)
	{
		sorted->i_lists = find_valid_lists(cur->value, sorted);
		if (!sorted->i_lists)
		{
			sorted->lists[*count] = create_new_list(cur->value, min, sorted);
			(*count)++;
		}
		else
			add_to_lists(cur->value, sorted);
		if (cur->next)
			cur = cur->next;
		else
			cur = sorted->stacks->stack_a;
	}
	best_list = find_best_list(sorted->lists, *count);
	free(sorted->lists);
	return (best_list);
}

t_stack	*pre_sorted_list(t_stacks *stacks, int min)
{
	t_stack	*cur;
	t_lists	sorted;

	sorted.stacks = stacks;
	sorted.lists = ft_calloc(sizeof(t_stack *),
			(ft_lstsize(stacks->stack_a) + 1));
	if (!sorted.lists)
		exit_error(stacks);
	cur = stacks->stack_a;
	if (ft_lstlast(cur)->value != min)
	{
		while (cur->value != min && cur)
			cur = cur->next;
		cur = cur->next;
	}
	return (handlst(min, cur, &sorted));
}
