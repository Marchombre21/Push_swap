/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:29:57 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 15:42:45 by bfitte/gmac      ###   ########lyon.fr   */
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
	ft_printf("pa\n");
}

void	pb(t_count *count_op)
{
	if (!count_op->stack_a)
		return ;
	push_op(&count_op->stack_b, &count_op->stack_a);
	count_op->pb++;
	ft_printf("pb\n");
}
