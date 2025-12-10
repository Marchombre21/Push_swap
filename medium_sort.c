/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/10 23:29:20 by gildas           ###   ########lyon.fr   */
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

void sort_stack_b(t_stack **stack_b)
{
	int		sorted;
	int		i;
	int		size;
	int		max;

	sorted = 1;
	max = find_max(*stack_b);
	size = ft_lstsize(*stack_b);
	if (size <= 1)
		return ;
	while (sorted != 0)
	{
		sorted = 0;
		i = 1;
		while (i < size)
		{
			if ((*stack_b)->value < (*stack_b)->next->value)
			{
				sb(stack_b);
				rb(stack_b);
				sorted = 1;
			}
			else
				rb(stack_b);
			i++;
		}
	}
}

void	bucket_sort(t_stack **stack_a, t_stack **stack_b, int nb_buckets)
{
	int min;
	int max;
	int bucket_size;
	int i;
	int j;
	int size_a;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	bucket_size = (max - min + 1) / nb_buckets;
	size_a = ft_lstsize(*stack_a);
	if (bucket_size == 0)
		bucket_size = 1;
	i = 0;
	while (i < nb_buckets)
	{
		j = -1;
		while (++j < size_a)
		{
			if ((*stack_a)->value <= (min + (i + 1) * bucket_size) &&
				(*stack_a)->value >= (min + i * bucket_size))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		sort_stack_b(stack_b);
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

/* ****************************************************	*/
/* Bucket sort is used here								*/
/* ****************************************************	*/

int	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_buckets;

	nb_buckets = next_sqrt(ft_lstsize(*stack_a));
	if (nb_buckets <= 0)
		return (-1);
	bucket_sort(stack_a, stack_b, nb_buckets);
	return (0);
}
