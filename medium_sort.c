/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/19 17:05:06 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	b_push_limited(t_stacks *stacks, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pb(stacks);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(stacks);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(stacks);
// 		j--;
// 	}
// 	return (sorted);
// }

// int a_push_limited(t_stacks *stacks, int limit)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = limit - 1;
// 	pa(stacks);
// 	while (j > 0)
// 	{
// 		if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(stacks);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(stacks);
// 		j--;
// 	}
// 	return (sorted);
// }

// void	rev_bubble_sort_bucket(t_stacks *stacks, int limit)
// {
// 	if (limit == 0)
// 		return ;
// 	if (limit == 1)
// 		return (pa(stacks));
// 	while (a_push_limited(stacks, limit) != 0)
// 		b_push_limited(stacks, limit);
// }

int	fill_bucket(t_stacks *stacks, t_bucket bucket, int to_sort)
{
	int		i;
	t_stack	**s_a;
	t_stack	**s_b;

	s_a = &stacks->stack_a;
	s_b = &stacks->stack_b;
	i = 0;
	while (i++ < to_sort)
	{
		if ((*s_a)->value >= bucket.min && (*s_a)->value <= bucket.max)
		{
			pb(stacks);
			// if (s_b && (*s_b)->next && (*s_b)->value < (*s_b)->next->value)
			// 	sb(stacks);
			bucket.count++;
		}
		else
			ra(stacks);
	}
	return (bucket.count);
}

void    bucket_sort(t_stacks *stacks, t_bucket *buckets, int nb)
{
    int            i;
    int            to_sort;
    int            max_b;
    int            size_a;
    t_bucket    bucket;

    size_a = ft_lstsize(stacks->stack_a);
    to_sort = size_a;
    i = 0;
    while (i < nb && to_sort > 0)
    {
        bucket = buckets[i];
        to_sort -= fill_bucket(stacks, bucket, to_sort);
        i++;
    }
    while (stacks->stack_b)
    {
        size_a = ft_lstsize(stacks->stack_a);
        max_b = find_max(stacks->stack_b, ft_lstsize(stacks->stack_b));
        rot_top(get_ops(stacks, 'b'), max_b, stacks);
        pa(stacks);
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
		bucket_size = 1;
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

/* ****************************************************	*/
/* Bucket sort --> get number of buckets then call sort	*/
/* ****************************************************	*/

int	medium_sort(t_stacks *stacks)
{
	int			nb_buckets;
	int			min;
	int			max;
	int			size_a;
	t_bucket	*buckets;

	if (!stacks->stack_a || ft_lstsize(stacks->stack_a) <= 1)
		return (-1);
	size_a = ft_lstsize(stacks->stack_a);
	min = find_min(stacks->stack_a, size_a);
	max = find_max(stacks->stack_a, size_a);
	nb_buckets = next_sqrt(size_a);
	if (nb_buckets <= 0)
		return (-1);
	buckets = init_buckets(nb_buckets, min, max);
	if (!buckets)
		return (-1);
	bucket_sort(stacks, buckets, nb_buckets);
	return (0);
}
