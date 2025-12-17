/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:21:51 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/17 12:27:48 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_op(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stacks *stacks)
{
	rotate_op(&stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	rotate_op(&stacks->stack_b);
}

void	rr(t_stacks *stacks)
{
	rotate_op(&stacks->stack_a);
	rotate_op(&stacks->stack_b);
}
