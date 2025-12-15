/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:17:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 13:06:06 by bfitte/gmac      ###   ########lyon.fr   */
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

void	sa(t_stack **stack_a)
{
	swap_op(stack_a);
	(*stack_a)->sa++;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_op(stack_b);
	(*stack_b)->sb++;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_op(stack_a);
	swap_op(stack_b);
	(*stack_a)->ss++;
	ft_printf("ss\n");
}
