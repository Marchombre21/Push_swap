/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/19 18:23:25 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	refill_a(t_stacks *stacks)
{
	while (stacks->stack_b)
		pa(stacks);
}

static int	init(t_stacks *stacks, int *min, int *max)
{
	pb(stacks);
	if ((stacks->stack_a)->value > (stacks->stack_b)->value)
	{
		*min = (stacks->stack_b)->value;
		pb(stacks);
		*max = (stacks->stack_b)->value;
	}
	else
	{
		*min = (stacks->stack_a)->value;
		*max = (stacks->stack_b)->value;
		pb(stacks);
	}
	return (2);
}

static void	exec(t_stacks *stacks, int to_sort)
{
	int		min_b;
	int		max_b;
	t_ops	b_ops;

	min_b = 0;
	max_b = 0;
	to_sort -= init(stacks, &min_b, &max_b);
	while (to_sort-- > 0)
	{
		b_ops = get_ops(stacks, 'b');
		if ((stacks->stack_a)->value < min_b)
		{
			rot_bottom(b_ops, min_b, stacks);
			min_b = (stacks->stack_a)->value;
		}
		else if ((stacks->stack_a)->value > max_b)
		{
			rot_top(b_ops, max_b, stacks);
			max_b = (stacks->stack_a)->value;
		}
		else
			rot_spot(b_ops, (stacks->stack_a)->value, stacks);
		pb(stacks);
	}
}

/**
 * @brief Sorts a stack with an insertion sorting algorithm.
 */
int	simple_sort(t_stacks *stacks)
{
	int		max;
	int		size_a;

	size_a = ft_lstsize(stacks->stack_a);
	max = find_max(stacks->stack_a, size_a);
	exec(stacks, size_a);
	rot_top(get_ops(stacks, 'b'), max, stacks);
	refill_a(stacks);
	return (0);
}
