/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:21:51 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/17 09:53:54 by bfitte           ###   ########lyon.fr   */
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
	stacks->ra++;
	stacks->total++;
	ft_printf("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate_op(&stacks->stack_b);
	stacks->rb++;
	stacks->total++;
	ft_printf("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate_op(&stacks->stack_a);
	rotate_op(&stacks->stack_b);
	stacks->rr++;
	stacks->total++;
	ft_printf("rr\n", 1);
}
