/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_simple_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 11:07:06 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	init(t_stack **stack_a, t_stack **stack_b, int *min, int *max)
{
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
	return (2);
}

static void	exec(t_stack **s_a, t_stack **s_b, int to_sort)
{
	int	min_a;
	int	max_a;

	min_a = 0;
	max_a = 0;
	to_sort -= init(s_a, s_b, &min_a, &max_a);
	while (to_sort-- > 0)
	{
		if ((*s_b)->value < min_a)
		{
			rot_top(get_stack_ops(s_a, 'a'), min_a);
			pa(s_a, s_b);
			min_a = (*s_a)->value;
		}
		else if ((*s_b)->value > max_a)
		{
			rot_bottom(get_stack_ops(s_a, 'a'), max_a);
			pa(s_a, s_b);
			max_a = (*s_a)->value;
		}
		else
		{
			rot_spot(get_stack_ops(s_a, 'a'), (*s_b)->value);
			pa(s_a, s_b);
		}
	}
}

void	rev_simple_sort(t_stack **stack_a, t_stack **stack_b, int to_sort)
{
	int	min;

	if (to_sort == 0)
		return ;
	if (to_sort == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	min = find_min(*stack_b, to_sort);
	exec(stack_a, stack_b, to_sort);
	rot_bottom(get_stack_ops(stack_a, 'a'), min);
}
