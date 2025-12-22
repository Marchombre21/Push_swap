/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:35:06 by bfitte            #+#    #+#             */
/*   Updated: 2025/12/22 10:10:44 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_error(t_stacks *stacks)
{
	ft_lstclear(&stacks->stack_a);
	ft_lstclear(&stacks->stack_b);
	ft_printf("Malloc error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_presorted(int value, t_stack *pre_sorted)
{
	t_stack	*current;

	current = pre_sorted;
	while (current)
	{
		if (value == current->value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_all_lists(t_lists *sorted)
{
	int	i;

	if (!sorted->lists)
		return ;
	i = 0;
	while (i < sorted->list_count)
	{
		if (sorted->lists[i])
			ft_lstclear(&sorted->lists[i]);
		i++;
	}
	free(sorted->lists);
}

t_stack	*create_new_list(int value, int min, t_lists *sorted)
{
	t_stack	*new;
	t_stack	*second;

	new = ft_lstnew(min);
	if (!new)
	{
		free_all_lists(sorted);
		exit_error(sorted->stacks);
	}
	second = ft_lstnew(value);
	if (!second)
	{
		free(new);
		free_all_lists(sorted);
		exit_error(sorted->stacks);
	}
	new->next = second;
	return (new);
}

t_stack	*list_to_sort(t_lists *sorted, t_stack *best_list)
{
	t_stack	*stack_a;
	t_stack *to_sort;
	t_stack *new_node;

	to_sort = NULL;
	stack_a = sorted->stacks->stack_a;
	while (stack_a)
	{
		if (stack_a->value != best_list->value)
		{
			new_node = ft_lstnew(stack_a->value);
			if (!new_node)
			{
				ft_lstclear(&to_sort);
				free_all_lists(sorted);
				exit_error(sorted->stacks);
			}
			ft_lstadd_back(&to_sort, new_node);
		}
		stack_a = stack_a->next;
	}
	return (to_sort);
}

t_stack	*lf_next(t_stacks *stacks, t_stack *to_sort_lst)
{
	int		first;
	int		last;
	t_stack	*last_node;
	t_stack	*tmp;

	tmp =  NULL;
	last_node = ft_lstlast(to_sort_lst);
	first = count_nodes_until_value(stacks->stack_a, to_sort_lst->value);
	last = count_nodes_until_value(stacks->stack_a, last_node->value);
	if (first <= last)
	{
		rot_top(get_ops(stacks, 'a'), to_sort_lst->value, stacks);
		tmp = to_sort_lst;
		to_sort_lst = to_sort_lst->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		rot_top(get_ops(stacks, 'a'), last_node->value, stacks);
		free(last_node);
		last_node = NULL;
	}
	return (to_sort_lst);
}
