/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_simple_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:26:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/17 09:53:54 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	init(t_stacks *stacks, int *min, int *max)
{
	pa(stacks);
	if ((stacks->stack_b)->value > (stacks->stack_a)->value)
	{
		*min = (stacks->stack_a)->value;
		*max = (stacks->stack_b)->value;
		pa(stacks);
		sa(stacks);
	}
	else
	{
		*min = (stacks->stack_b)->value;
		*max = (stacks->stack_a)->value;
		pa(stacks);
	}
	return (2);
}

static void	exec(t_stacks *stacks, int to_sort)
{
	int	min_a;
	int	max_a;

	min_a = 0;
	max_a = 0;
	to_sort -= init(stacks, &min_a, &max_a);
	while (to_sort-- > 0)
	{
		if ((stacks->stack_b)->value < min_a)
		{
			rot_top(get_ops(stacks, 'a'), min_a, stacks);
			min_a = (stacks->stack_b)->value;
		}
		else if ((stacks->stack_b)->value > max_a)
		{
			rot_bottom(get_ops(stacks, 'a'), max_a, stacks);
			max_a = (stacks->stack_b)->value;
		}
		else
			rot_spot(get_ops(stacks, 'a'),
				(stacks->stack_b)->value, stacks);
		pa(stacks);
	}
}

void	rev_simple_sort(t_stacks *stacks, int to_sort)
{
	int	min;

	if (to_sort == 0)
		return ;
	if (to_sort == 1)
	{
		pa(stacks);
		return ;
	}
	min = find_min(stacks->stack_b, to_sort);
	exec(stacks, to_sort);
	rot_bottom(get_ops(stacks, 'a'), min, stacks);
}
