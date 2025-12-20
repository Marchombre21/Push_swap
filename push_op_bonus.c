/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:29:57 by gmach             #+#    #+#             */
/*   Updated: 2025/12/20 09:15:11 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_op(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!src || !*src || !dest)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_stacks *stacks)
{
	if (!stacks->stack_b)
		return ;
	push_op(&stacks->stack_a, &stacks->stack_b);
}

void	pb(t_stacks *stacks)
{
	if (!stacks->stack_a)
		return ;
	push_op(&stacks->stack_b, &stacks->stack_a);
}
