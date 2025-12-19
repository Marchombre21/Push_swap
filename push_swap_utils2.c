/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:06:59 by gmach             #+#    #+#             */
/*   Updated: 2025/12/19 18:16:35 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_ops	get_ops(t_stacks *stacks, char which)
{
	t_ops	ops;

	if (which == 'a')
	{
		ops.letter = 'a';
		ops.ptr = stacks->stack_a;
		ops.rotate = &ra;
		ops.rrotate = &rra;
		ops.swap = &sa;
	}
	else
	{
		ops.letter = 'b';
		ops.ptr = stacks->stack_b;
		ops.rotate = &rb;
		ops.rrotate = &rrb;
		ops.swap = &sb;
	}
	return (ops);
}

int	count_nodes_to_spot(t_ops ops, int value, int to_sort)
{
	int		spot_pos;
	int		min;
	int		max;
	t_stack	*current;

	min = find_min(ops.ptr, to_sort);
	max = find_max(ops.ptr, to_sort);
	spot_pos = 1;
	current = ops.ptr;
	while (current && current->next)
	{
		if (ops.letter == 'b')
		{
			if (value < current->value && value > current->next->value
				&& !(current->value == min && current->next->value == max))
				return (spot_pos);
		}
		else if (ops.letter == 'a')
			if (value > current->value && value < current->next->value
				&& !(current->value == max && current->next->value == min))
				return (spot_pos);
		spot_pos++;
		current = current->next;
	}
	return (spot_pos);
}

int	rot_top(t_ops ops, int value, t_stacks *stacks)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = ft_lstsize(ops.ptr);
	count = count_nodes_until_value(ops.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < count)
			ops.rotate(stacks);
	}
	else
	{
		count = size - count;
		while (i++ < count)
			ops.rrotate(stacks);
	}
	return (count);
}

int	rot_bottom(t_ops ops, int value, t_stacks *stacks)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = ft_lstsize(ops.ptr);
	count = size - count_nodes_until_value(ops.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < (count - 1))
			ops.rrotate(stacks);
	}
	else
	{
		count = size - count;
		while (i++ <= count)
			ops.rotate(stacks);
	}
	return (count);
}

int	rot_spot(t_ops ops, int value, t_stacks *stacks)
{
	int	i;
	int	spot_pos;
	int	size;

	i = 0;
	size = ft_lstsize(ops.ptr);
	spot_pos = count_nodes_to_spot(ops, value, size);
	if (spot_pos <= size / 2)
		while (i++ < spot_pos)
			ops.rotate(stacks);
	else
	{
		spot_pos = size - spot_pos;
		while (i++ < spot_pos)
			ops.rrotate(stacks);
	}
	return (spot_pos);
}
