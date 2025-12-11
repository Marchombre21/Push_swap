/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/11 17:28:58 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->next && stack_a->value < stack_a->next->value)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	sort(t_stack **a, t_stack **b, int shift_byte, int size)
{
	while (size-- != 0)
	{
		if ((*a)->value >> shift_byte & 1)
			ra(a);
		else
			pb(a, b);
	}
	size = ft_lstsize(*b);
	while (size-- != 0)
		pa(a, b);
	return(check_sort(*a));
}


int	find_max_complex(t_stack *a)
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

void sort_array(int *tab, int size)
{
	int i;
	int j;
	int tmp;

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

void	transform_to_index(t_stack *a, int size)
{
	int	array[size];
	int	i;
	t_stack	*b;

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
		while (array[++i])
			if(array[i] == b->value)
				b->value = i;
		b = b->next;
	}
}

void	complex_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max;
	int	i;
	int	is_sorted;

	is_sorted = 0;
	size = ft_lstsize(*a);
	i = 0;
	transform_to_index(*a, size);
	max = find_max_complex(*a);
	while (i <= max && is_sorted != (size - 1))
		is_sorted = sort(a, b, i++, size);
}
