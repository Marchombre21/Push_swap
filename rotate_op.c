/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:21:51 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 15:32:58 by bfitte/gmac      ###   ########lyon.fr   */
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

void	ra(t_count *count_op)
{
	rotate_op(&count_op->stack_a);
	count_op->ra++;
	ft_printf("ra\n");
}

void	rb(t_count *count_op)
{
	rotate_op(&count_op->stack_b);
	count_op->rb++;
	ft_printf("rb\n");
}

void	rr(t_count *count_op)
{
	rotate_op(&count_op->stack_a);
	rotate_op(&count_op->stack_b);
	count_op->rr++;
	ft_printf("rr\n");
}
