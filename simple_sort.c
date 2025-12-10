/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/10 11:20:44 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int 	size;

	i = 1;
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	while (i < size / 2)
	{
		j = size;
		while (j > 0)
		{
			if (!*stack_b)
				pb(stack_a, stack_b);
			else if (*stack_a < *stack_b)
			{
				pb(stack_a, stack_b);
				sb(stack_b);
			}
			else
				pb(stack_a, stack_b);
			j--;
		}
		j = size;
		while (j > 0)
		{
			pa(stack_a, stack_b);
			j--;
		}
		i++;
	}
}


