/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:06:59 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 09:21:10 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack_ops	get_stack_ops(t_stack **stack, char which)
{
	t_stack_ops	s;

	if (which == 'a')
	{
		s.letter = 'a';
		s.ptr = stack;
		s.rotate = &ra;
		s.rrotate = &rra;
		s.swap = &sa;
	}
	else
	{
		s.letter = 'b';
		s.ptr = stack;
		s.rotate = &rb;
		s.rrotate = &rrb;
		s.swap = &sb;
	}
	return (s);
}

int	count_nodes_to_spot(t_stack_ops s, int value, int to_sort)
{
	int		spot_pos;
	int		min;
	int		max;
	t_stack	*current;

	min = find_min(*s.ptr, to_sort);
	max = find_max(*s.ptr, to_sort);
	spot_pos = 1;
	current = *s.ptr;
	while (current && current->next)
	{
		if (s.letter == 'b')
		{
			if (value < current->value && value > current->next->value
				&& !(current->value == min && current->next->value == max))
				return (spot_pos);
		}
		else if (s.letter == 'a')
		{
			if (value > current->value && value < current->next->value
				&& !(current->value == max && current->next->value == min))
				return (spot_pos);
		}
		spot_pos++;
		current = current->next;
	}
	return (spot_pos);
}

int	rot_top(t_stack_ops s, int value, int size)
{
	int	i;
	int	count;

	i = 0;
	count = count_nodes_until_value(*s.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < count)
			s.rotate(s.ptr);
	}
	else
	{
		count = size - count;
		while (i++ < count)
			s.rrotate(s.ptr);
	}
	return (count);
}

int	rot_bottom(t_stack_ops s, int value, int size)
{
	int	i;
	int	count;

	i = 0;
	count = size - count_nodes_until_value(*s.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < count)
			s.rrotate(s.ptr);
	}
	else
	{
		count = size - count;
		while (i++ <= count)
			s.rotate(s.ptr);
	}
	return (count);
}

int	rot_spot(t_stack_ops s, int value, int size)
{
	int	i;
	int	spot_pos;

	i = 0;
	spot_pos = count_nodes_to_spot(s, value, size);
	if (spot_pos <= size / 2)
		while (i++ < spot_pos)
			s.rotate(s.ptr);
	else
	{
		spot_pos = size - spot_pos;
		while (i++ < spot_pos)
			s.rrotate(s.ptr);
	}
	return (spot_pos);
}
