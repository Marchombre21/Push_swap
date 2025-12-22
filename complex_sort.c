/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/22 21:37:12 by gildas           ###   ########lyon.fr   */
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
 * @brief Sort the array so that we can retrieve the indexes later.
 * @param tab The array
 * @param size Size of the array
 */
static void	sort_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Replace values of chained list by their index in sorted array.
 * @param a chained list
 * @param size Size of list to malloc the array
 * @param array Sorted array
 */
static void	transform_to_index(t_stack *a, int size, int *array)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == a->value)
			{
				a->value = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	free(array);
}

/**
 * @brief Put all values of chained list in array and sort the array.
 * @param a chained list
 * @param size Size of list to malloc the array
 */
static void	create_array(t_stacks *stacks, int size)
{
	int		*array;
	int		i;
	t_stack	*b;

	b = stacks->stack_a;
	array = ft_calloc(size + 1, sizeof(int));
	if (!array)
		exit_error(stacks);
	i = 0;
	while (b)
	{
		array[i++] = b->value;
		b = b->next;
	}
	sort_array(array, size);
	transform_to_index(stacks->stack_a, size, array);
}

void	complex_sort(t_stacks *stacks)
{
	int	size;
	int	max;
	int	i;
	
	size = ft_lstsize(stacks->stack_a);
	i = 0;
	create_array(stacks, size);
	max = find_max_complex(stacks->stack_a);
	while (i < max)
		sort(stacks, i++, size);
}
