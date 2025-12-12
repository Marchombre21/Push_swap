/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_reloaded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/12 19:08:47 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rel_rot_a_to_min(t_stack **stack_a, int target, int to_sort, int limit)
{
	int count;

	count = count_nodes_until_value(*stack_a, target);
	if (count <= to_sort / 2)
		while (to_sort > 0 && (ft_lstlast(*stack_a))->value != target)
		{
			ra(stack_a);
			to_sort--;
		}
	else
		while (to_sort > 0 && (ft_lstlast(*stack_a))->value != target)
		{
			rra(stack_a);
			to_sort--;
		}
}

void	rel_rot_a_to_max(t_stack **stack_a, int target, int size_a, int limit)
{
	int count;

	count = count_nodes_until_value(*stack_a, target);
	if (count <= size_a / 2)
		while (size_a > 0 && (*stack_a)->value != target)
		{
			ra(stack_a);
			size_a--;
		}
	else
		while (size_a > 0 && (*stack_a)->value != target)
		{
			rra(stack_a);
			size_a--;
		}
}

int	rel_count_to_spot(t_stack *stack_a, int value)
{
	int	spot_pos;
	t_stack	*current;
	int	min_a;
	int	max_a;

	min_a = find_min(stack_a);
	max_a = find_max(stack_a);
	spot_pos = 1;
	current = stack_a;
	while (current && current->next)
	{
		if (value < current->value && value > current->next->value && !(current->value == min_a && current->next->value == max_a))
			return (spot_pos);
		spot_pos++;
		current = current->next;
	}
	return (spot_pos);
}
int	rel_rot_a_to_spot(t_stack **stack_a, int value, int size_a)
{
	int	spot_pos;

	spot_pos = rel_count_to_spot(*stack_a, value);
	if (spot_pos == -1)
		return (-1);
	if (spot_pos <= size_a / 2)
		while (spot_pos-- > 0)
			ra(stack_a);
	else
		while (size_a-- > spot_pos)
			rra(stack_a);
	return (0);
}

int	simple_sort_reloaded(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	i;
	int	min_a_rel;
	int	max_a_rel;
	int to_sort;

	i = 0;
	if (limit == 0)
		return (0);
	if (limit == 1)
	{
		pa(stack_a, stack_b);
		return (0);
	}
	//init 2 first terms in A
	pa(stack_a, stack_b);
	if ((*stack_b)->value > (*stack_a)->value)
	{
		min_a_rel = (*stack_a)->value;
		max_a_rel = (*stack_b)->value;
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else
	{
		min_a_rel = (*stack_b)->value;
		max_a_rel = (*stack_a)->value;
		pa(stack_a, stack_b);
	}
	limit -= 2;
	to_sort = 2;
	//insert rest of stack B into A
	while (i++ < limit)
	{
		if (to_sort < 2)
			return (-1);
		// check if top b is new min a and insert accordingly
		if ((*stack_b)->value < min_a_rel)
		{
			rel_rot_a_to_min(stack_a, min_a_rel, to_sort);
			pa(stack_a, stack_b);
			to_sort++;
			min_a_rel = (*stack_a)->value;
		}
		// check if top a is new max b and insert accordingly
		else if ((*stack_b)->value > max_a_rel)
		{
			rel_rot_a_to_max(stack_a, max_a_rel, to_sort);
			pa(stack_a, stack_b);
			to_sort++;
			max_a_rel = (*stack_a)->value;
		}
		// else find the right spot by rotating B
		else
		{
			if (rel_rot_a_to_spot(stack_a, (*stack_b)->value, to_sort) == -1)
				return (-1);
			pa(stack_a, stack_b);
			to_sort++;
		}
	}
	rel_rot_a_to_max(stack_a, max_a_rel, to_sort, limit);
	return (0);
}
