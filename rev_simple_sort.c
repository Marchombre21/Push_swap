/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_simple_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 16:50:23 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	init(t_count *count_op, int *min, int *max)
{
	pa(count_op);
	if ((count_op->stack_b)->value > (count_op->stack_a)->value)
	{
		*min = (count_op->stack_a)->value;
		*max = (count_op->stack_b)->value;
		pa(count_op);
		sa(count_op);
	}
	else
	{
		*min = (count_op->stack_b)->value;
		*max = (count_op->stack_a)->value;
		pa(count_op);
	}
	return (2);
}

static void	exec(t_count *count_op, int to_sort)
{
	int	min_a;
	int	max_a;

	min_a = 0;
	max_a = 0;
	to_sort -= init(count_op, &min_a, &max_a);
	while (to_sort-- > 0)
	{
		if ((count_op->stack_b)->value < min_a)
		{
			rot_top(get_stack_ops(count_op, 'a'), min_a, count_op);
			min_a = (count_op->stack_b)->value;
		}
		else if ((count_op->stack_b)->value > max_a)
		{
			rot_bottom(get_stack_ops(count_op, 'a'), max_a, count_op);
			max_a = (count_op->stack_b)->value;
		}
		else
			rot_spot(get_stack_ops(count_op, 'a'), (count_op->stack_b)->value, count_op);
		pa(count_op);
	}
}

void	rev_simple_sort(t_count *count_op, int to_sort)
{
	int	min;

	if (to_sort == 0)
		return ;
	if (to_sort == 1)
	{
		pa(count_op);
		return ;
	}
	min = find_min(count_op->stack_b, to_sort);
	exec(count_op, to_sort);
	rot_bottom(get_stack_ops(count_op, 'a'), min, count_op);
}
