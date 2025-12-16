/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:21:51 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/16 13:19:53 by bfitte           ###   ########lyon.fr   */
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
	count_op->total++;
	ft_printf("ra\n", 1);
}

void	rb(t_count *count_op)
{
	rotate_op(&count_op->stack_b);
	count_op->rb++;
	count_op->total++;
	ft_printf("rb\n", 1);
}

void	rr(t_count *count_op)
{
	rotate_op(&count_op->stack_a);
	rotate_op(&count_op->stack_b);
	count_op->rr++;
	count_op->total++;
	ft_printf("rr\n", 1);
}
