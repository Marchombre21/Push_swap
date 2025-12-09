/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/09 16:27:39 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int 	size;
	t_stack	*temp;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < size)
	{
		temp = *stack_a;
		if (temp->value > temp->next->value)
		{
			sa(stack_a);
			i = 0;
		}
		rra(stack_a);
		i++;
	}
}

