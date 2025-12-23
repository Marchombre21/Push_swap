/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:35:06 by bfitte            #+#    #+#             */
/*   Updated: 2025/12/23 09:28:37 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_malloc(t_stacks *stacks)
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
		exit_malloc(sorted->stacks);
	}
	second = ft_lstnew(value);
	if (!second)
	{
		free(new);
		free_all_lists(sorted);
		exit_malloc(sorted->stacks);
	}
	new->next = second;
	return (new);
}

/**
 * @brief Find the highest number of the list then find the place of the last 1
 * in his bit version.
 * @param a The chained list.
 */
int	find_max_complex(t_stack *a)
{
	int	max;
	int	shift_byte;

	shift_byte = 0;
	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	while (max >> shift_byte != 0)
		shift_byte++;
	return (shift_byte);
}
