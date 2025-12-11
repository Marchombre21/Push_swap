/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:58:46 by gmach             #+#    #+#             */
/*   Updated: 2025/12/11 10:59:09 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	next_sqrt(int nb)
{
	double	root;
	double	last;
	double	diff;

	if (nb <= 0)
		return (-1);
	root = nb / 3;
	diff = 1;
	while (diff >= 1)
	{
		last = root;
		root = (root + (nb / root)) / 2;
		diff = last - root;
	}
	if ((int)(root) * (int)(root) == nb)
		return ((int)root);
	return ((int)root + 1);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}
