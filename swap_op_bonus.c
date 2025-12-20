/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:17:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/20 09:15:39 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_op(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stacks *stacks)
{
	swap_op(&stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	swap_op(&stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	swap_op(&stacks->stack_a);
	swap_op(&stacks->stack_b);
}
