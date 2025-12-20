/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/20 15:05:17 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort(t_stacks *stacks, int shift_byte, int size)
{
	while (size > 0)
	{
		if (((stacks->stack_a)->value >> shift_byte & 1))
			ra(stacks);
		else
			if (size > 1)
				pb(stacks);
		size--;
	}
	size = ft_lstsize(stacks->stack_b);
	while (size-- > 0)
		pa(stacks);
}

/**
 * @brief Find the highest number of the list then find the place of the last 1
 * in his bit version.
 * @param a The chained list.
 */
static int	find_max_complex(t_stack *a)
{
	int	max;
	int	shift_byte;

	shift_byte = 0;
	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	while (max >> shift_byte != 0)
		shift_byte++;
	return (shift_byte);
}



/**
 * @brief Put all values of chained list in array, sort the array and replace
 * values of chained list by their index in sorted array.
 * @param a chained list
 * @param size Size of list to malloc the array
 */
static void	transform_to_index(t_stack *a, int size)
{
	int		*array;
	int		i;
	t_stack	*b;

	array = ft_calloc(size + 1, sizeof(int));
	if (!array)
		return ;
	b = a;
	i = 0;
	while (a)
	{
		array[i++] = a->value;
		a = a->next;
	}
	sort_array(array, size);
	while (b)
	{
		i = -1;
		while (++i < size)
			if (array[i] == b->value)
				b->value = i;
		b = b->next;
	}
	free(array);
}

void	complex_sort(t_stacks *stacks)
{
	int	size;
	int	max;
	int	i;
	int	is_sorted;

	is_sorted = 0;
	size = ft_lstsize(stacks->stack_a);
	i = 0;
	transform_to_index(stacks->stack_a, size);
	max = find_max_complex(stacks->stack_a);
	while (i < max)
		sort(stacks, i++, size);
}
