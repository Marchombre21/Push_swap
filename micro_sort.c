/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:42:51 by gmach             #+#    #+#             */
/*   Updated: 2026/01/05 11:44:23 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a->value > stacks->stack_a->next->value)
		sa(stacks);
}

static void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->stack_a->value;
	second = stacks->stack_a->next->value;
	third = stacks->stack_a->next->next->value;
	if (first > second && second < third && first < third)
		sa(stacks);
	else if (first > second && second > third && first > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > second && second < third && first > third)
		ra(stacks);
	else if (first < second && second > third && first < third)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first < second && second > third && first > third)
		rra(stacks);
}

void	micro_sort(t_stacks *stacks)
{
	int	size;

	size = ft_lstsize(stacks->stack_a);
	if (size < 2)
		return ;
	if (size == 2)
		sort_two(stacks);
	else if (size == 3)
		sort_three(stacks);
}
