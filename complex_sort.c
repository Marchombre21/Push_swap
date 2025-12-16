/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 15:06:13 by bfitte/gmac      ###   ########lyon.fr   */
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

int	sort(t_count *count_op, int shift_byte, int size)
{
	while (size-- > 0)
	{
		// if ((*a)->next && (*a)->value > (*a)->next->value)
		// 	sa(a);
		if (((count_op->stack_a)->value >> shift_byte & 1))
		{
			ra(count_op);
			// if (ft_lstsize(*b) == 0)
			// 	if (check_sort(*a) == size)
			// 		return (size + 1);
		}
		// else if (!((*a)->value >> shift_byte & 1) && ((*a)->value >> (shift_byte + 1) & 1))
		// 	pb(a, b);
		else
		{
			// if (((*a)->value >> shift_byte & 1) && ((*a)->value >> (shift_byte + 1) & 1))
			// {
			// 	rr(a, b);
			// 	size--;
			// }	
			// else
			// 	rb(b);
			if (size > 1)
				pb(count_op);
		}
		// if ((*a)->next && (*a)->value > (*a)->next->value)
		// 	sa(a);
	}
	size = ft_lstsize(count_op->stack_b);
	while (size-- > 0)
	{
		pa(count_op);
		// if ((*a)->next && (*a)->value > (*a)->next->value)
		// 	sa(a);
	}
	return(check_sort(count_op->stack_a));
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

void	complex_sort(t_count *count_op)
{
	int	size;
	int	max;
	int	i;
	int	is_sorted;

	is_sorted = 0;
	size = ft_lstsize(count_op->stack_a);
	i = 0;
	transform_to_index(count_op->stack_a, size);
	max = find_max_complex(count_op->stack_a);
	while (i < max && is_sorted != size)
		is_sorted = sort(count_op, i++, size);
}
