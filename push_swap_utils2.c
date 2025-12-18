/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:06:59 by gmach             #+#    #+#             */
/*   Updated: 2025/12/18 16:12:39 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_ops	get_ops(t_stacks *stacks, char which)
{
	t_ops	s;

	if (which == 'a')
	{
		s.letter = 'a';
		s.ptr = stacks->stack_a;
		s.rotate = &ra;
		s.rrotate = &rra;
		s.swap = &sa;
	}
	else
	{
		s.letter = 'b';
		s.ptr = stacks->stack_b;
		s.rotate = &rb;
		s.rrotate = &rrb;
		s.swap = &sb;
	}
	return (s);
}

int	count_nodes_to_spot(t_ops s, int value, int to_sort)
{
	int		spot_pos;
	int		min;
	int		max;
	t_stack	*current;

	min = find_min(s.ptr, to_sort);
	max = find_max(s.ptr, to_sort);
	spot_pos = 1;
	current = s.ptr;
	while (current && current->next)
	{
		if (s.letter == 'b')
		{
			if (value < current->value && value > current->next->value
				&& !(current->value == min && current->next->value == max))
				return (spot_pos);
		}
		else if (s.letter == 'a')
			if (value > current->value && value < current->next->value
				&& !(current->value == max && current->next->value == min))
				return (spot_pos);
		spot_pos++;
		current = current->next;
	}
	return (spot_pos);
}

int	rot_top(t_ops s, int value, t_stacks *stacks)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = ft_lstsize(s.ptr);
	count = count_nodes_until_value(s.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < count)
			s.rotate(stacks);
	}
	else
	{
		count = size - count;
		while (i++ < count)
			s.rrotate(stacks);
	}
	return (count);
}

int	rot_bottom(t_ops s, int value, t_stacks *stacks)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = ft_lstsize(s.ptr);
	count = size - count_nodes_until_value(s.ptr, value);
	if (count == 0)
		return (0);
	if (count <= size / 2)
	{
		while (i++ < count)
			s.rrotate(stacks);
	}
	else
	{
		count = size - count;
		while (i++ <= count)
			s.rotate(stacks);
	}
	return (count);
}

int	rot_spot(t_ops s, int value, t_stacks *stacks)
{
	int	i;
	int	spot_pos;
	int	size;

	i = 0;
	size = ft_lstsize(s.ptr);
	spot_pos = count_nodes_to_spot(s, value, size);
	if (spot_pos <= size / 2)
		while (i++ < spot_pos)
			s.rotate(stacks);
	else
	{
		spot_pos = size - spot_pos;
		while (i++ < spot_pos)
			s.rrotate(stacks);
	}
	return (spot_pos);
}
