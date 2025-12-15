/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/15 16:49:15 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	b_push_limited(t_count *count_op, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pb(count_op);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(count_op);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(count_op);
// 		j--;
// 	}
// 	return (sorted);
// }

// int a_push_limited(t_count *count_op, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pa(count_op);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(count_op);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(count_op);
// 		j--;
// 	}
// 	return (sorted);
// }

// void	rev_bubble_sort_bucket(t_count *count_op, int limit)
// {
// 	if (limit == 0)
// 		return ;
// 	if (limit == 1)
// 		return (pa(count_op));
// 	while (a_push_limited(count_op, limit) != 0)
// 		b_push_limited(count_op, limit);
// }

int	fill_bucket(t_count *count_op, t_bucket bucket, int to_sort)
{
	int	i;
	t_stack	**s_a;
	t_stack	**s_b;

	s_a = &count_op->stack_a;
	s_b = &count_op->stack_b;
	i = 0;
	while (i++ < to_sort)
	{
		if ((*s_a)->value >= bucket.min && (*s_a)->value <= bucket.max)
		{
			pb(count_op);
			if (s_b && (*s_b)->next && (*s_b)->value < (*s_b)->next->value)
				sb(count_op);
			bucket.count++;
		}
		else
			ra(count_op);
	}
	return (bucket.count);
}

void	reset_stack_a(t_count *count_op, int to_sort, int count, int size_a)
{
	int	i;

	i = 0;
	if (size_a - to_sort < to_sort - count)
		while (i++ < size_a - to_sort)
			ra(count_op);
	else
		while (i++ < to_sort - count)
			rra(count_op);
}

void	bucket_sort(t_count *count_op, t_bucket *buckets, int nb)
{
	int			i;
	int			to_sort;
	int			size_a;
	int			marker;
	t_bucket	bucket;

	size_a = ft_lstsize(count_op->stack_a);
	to_sort = size_a;
	i = 0;
	while (i < nb && to_sort > 0)
	{
		bucket = buckets[i];
		bucket.count = fill_bucket(count_op, bucket, to_sort);
		marker = find_max(count_op->stack_b, bucket.count);
		if (i != 0)
			reset_stack_a(count_op, to_sort, bucket.count, size_a);
		rev_simple_sort(count_op, bucket.count);
		rot_bottom(get_stack_ops(count_op, 'a'), marker, count_op);
		to_sort -= bucket.count;
		i++;
	}
	rot_top(get_stack_ops(count_op, 'a'), buckets[0].min, count_op);
}

t_bucket	*init_buckets(int nb_buckets, int min, int max)
{
	t_bucket	*buckets;
	int			i;
	int			bucket_size;

	bucket_size = (max - min + 1) / nb_buckets;
	if (bucket_size == 0)
		bucket_size = 1;
	buckets = malloc(sizeof(t_bucket) * nb_buckets);
	if (!buckets)
		return (NULL);
	i = 0;
	while (i < nb_buckets)
	{
		buckets[i].min = min + i * bucket_size;
		buckets[i].max = min + (i + 1) * bucket_size - 1;
		buckets[i].count = 0;
		buckets[i].number = i;
		i++;
	}
	return (buckets);
}

/* ****************************************************	*/
/* Bucket sort --> get number of buckets then call sort	*/
/* ****************************************************	*/

int	medium_sort(t_count *count_op)
{
	int			nb_buckets;
	int			min;
	int			max;
	int			size_a;
	t_bucket	*buckets;

	if (!count_op->stack_a || ft_lstsize(count_op->stack_a) <= 1)
		return (-1);
	size_a = ft_lstsize(count_op->stack_a);
	min = find_min(count_op->stack_a, size_a);
	max = find_max(count_op->stack_a, size_a);
	nb_buckets = next_sqrt(size_a);
	if (nb_buckets <= 0)
		return (-1);
	buckets = init_buckets(nb_buckets, min, max);
	if (!buckets)
		return (-1);
	bucket_sort(count_op, buckets, nb_buckets);
	return (0);
}
