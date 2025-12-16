/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:28:59 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/16 13:20:11 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_op(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev_last = *stack;
	last = ft_lstlast(*stack);
	while (prev_last->next != last)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_count *count_op)
{
	reverse_op(&count_op->stack_a);
	count_op->rra++;
	count_op->total++;
	ft_printf("rra\n", 1);
}

void	rrb(t_count *count_op)
{
	reverse_op(&count_op->stack_b);
	count_op->rrb++;
	count_op->total++;
	ft_printf("rrb\n", 1);
}

void	rrr(t_count *count_op)
{
	reverse_op(&count_op->stack_a);
	reverse_op(&count_op->stack_b);
	count_op->rrr++;
	count_op->total++;
	ft_printf("rrr\n", 1);
}
