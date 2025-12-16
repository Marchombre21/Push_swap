/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:58:46 by gmach             #+#    #+#             */
/*   Updated: 2025/12/16 15:12:13 by bfitte           ###   ########lyon.fr   */
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
	if ((int)(root) *(int)(root) == nb)
		return ((int)root);
	return ((int)root + 1);
}

int	find_min(t_stack *stack, int size)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack->next;
	while (current && size-- > 1)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack, int size)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current && size-- > 1)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	print_stack(t_stack *stack, char *name)
{
	t_stack	*current;

	ft_printf("Stack %s: ", 1, name);
	current = stack;
	while (current)
	{
		ft_printf("%d -> ", 1, current->value);
		current = current->next;
	}
	ft_printf("NULL\n", 1);
}

int	count_nodes_until_value(t_stack *stack, int value)
{
	int	count;

	count = 0;
	while (stack && stack->value != value)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
