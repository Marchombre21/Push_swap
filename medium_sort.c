/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/22 22:39:42 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	fill_bucket(t_stacks *stacks, t_bucket bucket, int to_sort)
{
	int		i;

	i = 0;
	while (i++ < to_sort)
	{
		if ((stacks->stack_a)->value >= bucket.min
			&& (stacks->stack_a)->value <= bucket.max)
		{
			pb(stacks);
			bucket.count++;
		}
		else
			ra(stacks);
	}
	return (bucket.count);
}

void	bucket_sort(t_stacks *stacks, t_bucket *buckets, int nb)
{
	int			i;
	int			to_sort;
	int			size_b;
	int			max_b;

	i = 0;
	to_sort = ft_lstsize(stacks->stack_a);
	while (i < nb)
		to_sort -= fill_bucket(stacks, buckets[i++], to_sort);
	size_b = ft_lstsize(stacks->stack_b);
	while (stacks->stack_b)
	{
		max_b = find_max(stacks->stack_b, size_b);
		rot_top(get_ops(stacks, 'b'), max_b, stacks);
		pa(stacks);
		size_b--;
	}
	rot_top(get_ops(stacks, 'a'), buckets[0].min, stacks);
}

t_bucket	*init_buckets(int nb_buckets, int min, int max)
{
	t_bucket	*buckets;
	int			i;
	float		bucket_size;

	bucket_size = (max - min) / (float)nb_buckets;
	if (bucket_size == 0)
		return (NULL);
	buckets = malloc(sizeof(t_bucket) * nb_buckets);
	if (!buckets)
		return (NULL);
	i = 0;
	while (i < nb_buckets)
	{
		buckets[i].min = min + i * bucket_size;
		buckets[i].max = min + (i + 1) * bucket_size;
		buckets[i].count = 0;
		buckets[i].number = i;
		i++;
	}
	return (buckets);
}

/**
 * @brief Sorts a stack using the bucket sort algorithm.
 */
void	medium_sort(t_stacks *stacks)
{
	int			nb_buckets;
	int			min;
	int			max;
	int			size_a;
	t_bucket	*buckets;

	size_a = ft_lstsize(stacks->stack_a);
	min = find_min(stacks->stack_a, size_a);
	max = find_max(stacks->stack_a, size_a);
	nb_buckets = next_sqrt(size_a);
	if (nb_buckets <= 0)
		exit_error(stacks);
	buckets = init_buckets(nb_buckets, min, max);
	if (!buckets)
		exit_error(stacks);
	bucket_sort(stacks, buckets, nb_buckets);
	free(buckets);
}
