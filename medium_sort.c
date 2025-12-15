/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 11:53:41 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	b_push_limited(t_stack **stack_a, t_stack **stack_b, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pb(stack_a, stack_b);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(stack_a, stack_b);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(stack_a, stack_b);
// 		j--;
// 	}
// 	return (sorted);
// }

// int a_push_limited(t_stack **stack_a, t_stack **stack_b, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pa(stack_a, stack_b);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(stack_a, stack_b);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(stack_a, stack_b);
// 		j--;
// 	}
// 	return (sorted);
// }

// void	rev_bubble_sort_bucket(t_stack **stack_a, t_stack **stack_b, int limit)
// {
// 	if (limit == 0)
// 		return ;
// 	if (limit == 1)
// 		return (pa(stack_a, stack_b));
// 	while (a_push_limited(stack_a, stack_b, limit) != 0)
// 		b_push_limited(stack_a, stack_b, limit);
// }

int	fill_bucket(t_stack **s_a, t_stack **s_b, t_bucket bucket, int to_sort)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i++ < to_sort)
	{
		if ((*s_a)->value >= bucket.min && (*s_a)->value <= bucket.max)
		{
			pb(s_a, s_b);
			if (s_b && (*s_b)->next && (*s_b)->value < (*s_b)->next->value)
				sb(s_b);
			count++;
		}
		else
			ra(s_a);
	}
	return (count);
}

int	rev_fill_bucket(t_stack **stack_a, t_stack **stack_b, int min, int max, int to_sort)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i++ < to_sort)
	{
		if ((*stack_a)->value >= min && (*stack_a)->value <= max)
		{
			pb(stack_a, stack_b);
			if (stack_b && (*stack_b)->next && (*stack_b)->value > (*stack_b)->next->value)
				sb(stack_b);
			count++;
		}
		else
			rra(stack_a);
	}
	return (count);
}

void	reset_stack_a(t_stack **stack_a, int to_sort, int count, int size_a)
{
	int	i;

	i = 0;
	if (size_a - to_sort < to_sort - count)
		while (i++ < size_a - to_sort)
			ra(stack_a);
	else
		while (i++ < to_sort - count)
			rra(stack_a);
}

void	bucket_sort(t_stack **s_a, t_stack **s_b, t_bucket *buckets, int nb)
{
	int	i;
	int	to_sort;
	int	count;
	int	size_a;
	int	marker;
	t_bucket	bucket;

	size_a = ft_lstsize(*s_a);
	to_sort = size_a;
	i = 0;
	count = 0;
	while (i < nb && to_sort > 0)
	{
		bucket = buckets[i];
		count = fill_bucket(s_a, s_b, bucket, to_sort);
		marker = find_max(*s_b, count);
		if (i != 0)
			reset_stack_a(s_a, to_sort, count, size_a);
		rev_simple_sort(s_a, s_b, count);
		rot_bottom(get_stack_ops(s_a, 'a'), marker);
		to_sort -= count;
		i++;
	}
	rot_top(get_stack_ops(s_a, 'a'), buckets[0].min);
}

t_bucket	*init_buckets(int nb_buckets, int min, int bucket_size)
{
	t_bucket	*buckets;
	int			i;

	buckets = malloc(sizeof(t_bucket) * nb_buckets);
	if (!buckets)
		return (NULL);
	i = 0;
	while (i < nb_buckets)
	{
		buckets[i].min = min + i * bucket_size;
		buckets[i].max = min + (i + 1) * bucket_size - 1;
		buckets[i].size = 0;
		buckets[i].number = i;
		i++;
	}
	return (buckets);
}

/* ****************************************************	*/
/* Bucket sort --> get number of buckets then call sort	*/
/* ****************************************************	*/

int	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_buckets;
	int	min;
	int	max;
	int	bucket_size;
	int	size_a;
	t_bucket	*buckets;

	if (!*stack_a || ft_lstsize(*stack_a) <= 1)
		return (-1);
	size_a = ft_lstsize(*stack_a);
	min = find_min(*stack_a, size_a);
	max = find_max(*stack_a, size_a);
	nb_buckets = next_sqrt(size_a);
	if (nb_buckets <= 0)
		return (-1);
	bucket_size = (max - min + 1) / nb_buckets;
	if (bucket_size == 0)
		bucket_size = 1;
	buckets = init_buckets(nb_buckets, min, bucket_size);
	if (!buckets)
		return (-1);
	bucket_sort(stack_a, stack_b, buckets, nb_buckets);
	return (0);
}
