/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:29:57 by gmach             #+#    #+#             */
/*   Updated: 2025/12/16 13:20:40 by bfitte           ###   ########lyon.fr   */
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

void	pa(t_count *count_op)
{
	if (!count_op->stack_a)
		return ;
	push_op(&count_op->stack_a, &count_op->stack_b);
	count_op->pa++;
	count_op->total++;
	ft_printf("pa\n", 1);
}

void	pb(t_count *count_op)
{
	if (!count_op->stack_a)
		return ;
	push_op(&count_op->stack_b, &count_op->stack_a);
	count_op->pb++;
	count_op->total++;
	ft_printf("pb\n", 1);
}
