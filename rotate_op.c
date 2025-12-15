/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:21:51 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 13:05:33 by bfitte/gmac      ###   ########lyon.fr   */
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

void	ra(t_stack **stack_a)
{
	rotate_op(stack_a);
	(*stack_a)->ra++;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_op(stack_b);
	(*stack_b)->rb++;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_op(stack_a);
	rotate_op(stack_b);
	(*stack_a)->rr++;
	ft_printf("rr\n");
}
