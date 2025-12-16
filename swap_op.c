/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:17:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/16 13:19:21 by bfitte           ###   ########lyon.fr   */
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

void	sa(t_count *count_op)
{
	swap_op(&count_op->stack_a);
	count_op->sa++;
	count_op->total++;
	ft_printf("sa\n", 1);
}

void	sb(t_count *count_op)
{
	swap_op(&count_op->stack_b);
	count_op->sb++;
	count_op->total++;
	ft_printf("sb\n", 1);
}

void	ss(t_count *count_op)
{
	swap_op(&count_op->stack_a);
	swap_op(&count_op->stack_b);
	count_op->ss++;
	count_op->total++;
	ft_printf("ss\n", 1);
}
