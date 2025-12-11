/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/11 12:23:05 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort(t_stack *a, t_stack *b, int div)
{

}

int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
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
	sort_array(&array, size);
	while (b)
	{
		i = -1;
		while (array[++i])
			if(array[i] == b->value)
				b->value == i;
		b = b->next;
	}
}

void	complex_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max;
	int	div;

	div = 1;
	size = ft_lstsize(a);
	
	max = find_max(*a);
	while ((max / div) > 0)
	{
		sort(*a, *b, div);
		div *= 10;
	}
}
