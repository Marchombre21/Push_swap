/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:17:16 by gmach             #+#    #+#             */
/*   Updated: 2025/12/08 18:19:16 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("sa\n");
}
void	sb(t_stack **stack_b)
{
	swap_op(stack_b);
	ft_printf("sb\n");
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_op(stack_a);
	swap_op(stack_b);
	ft_printf("ss\n");
}
