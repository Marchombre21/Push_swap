/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_simple_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/14 17:15:06 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_rev_simple_sort(t_stack **stack_a, t_stack **stack_b, int *min, int *max)
{
	//init 2 first terms in A
	pa(stack_a, stack_b);
	if ((*stack_b)->value > (*stack_a)->value)
	{
		*min = (*stack_a)->value;
		*max = (*stack_b)->value;
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else
	{
		*min = (*stack_b)->value;
		*max = (*stack_a)->value;
		pa(stack_a, stack_b);
	}
}

int	rev_simple_sort(t_stack **stack_a, t_stack **stack_b, int to_sort)
{
	int	i;
	int	min_a;
	int	max_a;
	int sorted;

	i = 0;
	min_a = 0;
	max_a = 0;
	if (to_sort == 0)
		return (0);
	if (to_sort == 1)
	{
		pa(stack_a, stack_b);
		return (0);
	}
	print_stack(*stack_b, "B initial");
	init_rev_simple_sort(stack_a, stack_b, &min_a, &max_a);
	print_stack(*stack_a, "A after init of 2");
	to_sort -= 2;
	sorted = 2;
	//insert rest of stack B into A
	while (i++ < to_sort)
	{
		// check if top b is new min a and insert accordingly
		if ((*stack_b)->value < min_a)
		{
			rotate_value_to_top(get_stack_ops(stack_a, 'a'), min_a, ft_lstsize(*stack_a));
			pa(stack_a, stack_b);
			sorted++;
			min_a = (*stack_a)->value;
		}
		// check if top a is new max b and insert accordingly
		else if ((*stack_b)->value > max_a)
		{
			rotate_value_to_bottom(get_stack_ops(stack_a, 'a'), max_a, ft_lstsize(*stack_a));
			pa(stack_a, stack_b);
			sorted++;
			max_a = (*stack_a)->value;
		}
		// else find the right spot by rotating B
		else
		{
			rotate_to_spot(get_stack_ops(stack_a, 'a'), (*stack_b)->value, ft_lstsize(*stack_a));
			pa(stack_a, stack_b);
			sorted++;
		}
	}
	print_stack(*stack_b, "B after refill A");
	ft_printf("count %d\n", rotate_value_to_bottom(get_stack_ops(stack_a, 'a'), min_a, sorted));
	return (0);
}
