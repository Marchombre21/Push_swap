/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_reloaded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/14 14:01:28 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	print_stack(*stack_b, "B initial");
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
	print_stack(*stack_a, "A after init of 2");
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
			rotate_value_to_top(get_stack_ops(stack_a, 'a'), min_a_rel, to_sort);
			pa(stack_a, stack_b);
			to_sort++;
			min_a_rel = (*stack_a)->value;
		}
		// check if top a is new max b and insert accordingly
		else if ((*stack_b)->value > max_a_rel)
		{
			rotate_value_to_bottom(get_stack_ops(stack_a, 'a'), max_a_rel, to_sort);
			pa(stack_a, stack_b);
			to_sort++;
			max_a_rel = (*stack_a)->value;
		}
		// else find the right spot by rotating B
		else
		{
			rotate_to_spot(get_stack_ops(stack_a, 'a'), (*stack_b)->value, to_sort);
			pa(stack_a, stack_b);
			to_sort++;
		}
	}
	print_stack(*stack_b, "B after refill A");
	rotate_value_to_top(get_stack_ops(stack_a, 'a'), min_a_rel, to_sort);
	return (0);
}
