/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/11 10:51:52 by gmach            ###   ########lyon.fr   */
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

int	b_push_limited(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	j;
	int	sorted;

	sorted = 0;
	j = limit - 1;
	pb(stack_a, stack_b);
	while (j > 0 || *stack_a)
	{
		if ((*stack_a)->value < (*stack_b)->value)
		{
			pb(stack_a, stack_b);
			sb(stack_b);
			sorted++;
		}
		else
			pb(stack_a, stack_b);
		j--;
	}
	return (sorted);
}

int a_push_limited(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	j;
	int	sorted;

	sorted = 0;
	j = limit - 1;
	pa(stack_a, stack_b);
	while (j > 0 || *stack_b)
	{
		if ((*stack_a)->value < (*stack_b)->value)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
			sorted++;
		}
		else
			pa(stack_a, stack_b);
		j--;
	}
	return (sorted);
}

void	rev_buble_sort_limited(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	sorted;

	sorted = 1;
	if (limit == 0)
		return ;
	if (limit == 1)
		return (pa(stack_a, stack_b));
	while (a_push_limited(stack_a, stack_b, limit) != 0)
		b_push_limited(stack_a, stack_b, limit);
}

void	bucket_sort(t_stack **stack_a, t_stack **stack_b, int nb_buckets)
{
	int min;
	int max;
	int bucket_size;
	int i;
	int j;
	int to_sort;
	int count;
	int size_a;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	bucket_size = (max - min + 1) / nb_buckets;
	to_sort = ft_lstsize(*stack_a);
	size_a = to_sort;
	if (bucket_size == 0)
		bucket_size = 1;
	i = 0;
	while (i < nb_buckets)
	{
		j = 0;
		count = 0;
		while (j++ < to_sort)
		{
			if ((*stack_a)->value <= (min + (i + 1) * bucket_size) &&
				(*stack_a)->value >= (min + i * bucket_size))
			{
				pb(stack_a, stack_b);
				count++;
			}
			else
				ra(stack_a);
		}
		j = 0;
		rev_buble_sort_limited(stack_a, stack_b, count);
		j = 0;
		while (j++ < size_a + count - to_sort)
			ra(stack_a);
		to_sort -= count;
		i++;
	}
}

/* ****************************************************	*/
/* Bucket sort --> get number of buckets then call sort	*/
/* ****************************************************	*/

int	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_buckets;

	if (!*stack_a || ft_lstsize(*stack_a) <= 1)
		return (-1);
	nb_buckets = next_sqrt(ft_lstsize(*stack_a));
	if (nb_buckets <= 0)
		return (-1);
	bucket_sort(stack_a, stack_b, nb_buckets);
	return (0);
}
