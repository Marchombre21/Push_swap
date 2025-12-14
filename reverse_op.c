/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:28:59 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/14 09:29:43 by gildas           ###   ########lyon.fr   */
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

void	rra(t_stack **a)
{
	reverse_op(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_op(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_op(a);
	reverse_op(b);
	ft_printf("rrr\n");
}
