/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:28:59 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/17 09:53:54 by bfitte           ###   ########lyon.fr   */
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

void	rra(t_stacks *stacks)
{
	reverse_op(&stacks->stack_a);
	stacks->rra++;
	stacks->total++;
	ft_printf("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	reverse_op(&stacks->stack_b);
	stacks->rrb++;
	stacks->total++;
	ft_printf("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	reverse_op(&stacks->stack_a);
	reverse_op(&stacks->stack_b);
	stacks->rrr++;
	stacks->total++;
	ft_printf("rrr\n", 1);
}
