/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/13 10:43:50 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	b_push_limited(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	j;
	int	sorted;

	sorted = 0;
	j = limit - 1;
	pb(stack_a, stack_b);
	while (j > 0)
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
	while (j > 0)
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

void	rev_bubble_sort_bucket(t_stack **stack_a, t_stack **stack_b, int limit)
{
	if (limit == 0)
		return ;
	if (limit == 1)
		return (pa(stack_a, stack_b));
	while (a_push_limited(stack_a, stack_b, limit) != 0)
		b_push_limited(stack_a, stack_b, limit);
}

int fill_bucket(t_stack **stack_a, t_stack **stack_b, int min, int max, int to_sort)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i++ < to_sort)
	{
		if ((*stack_a)->value >= min && (*stack_a)->value <= max)
		{
			pb(stack_a, stack_b);
			if (stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	return (count);
}

// void	prep_stack_a(t_stack **stack_a, int min)
// {
// 	int	size;
// 	int	i;

// 	size = ft_lstsize(*stack_a);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if ((*stack_a)->value == min)
// 			return ;
// 		rra(stack_a);
// 		i++;
// 	}
// }

void	bucket_sort(t_stack **stack_a, t_stack **stack_b, int nb_buckets, int bucket_size)
{
	int min;
	int i;
	int j;
	int to_sort;
	int count;
	int size_a;

	size_a = ft_lstsize(*stack_a);
	min = find_min(*stack_a, size_a);
	to_sort = size_a;
	i = 0;
	count = 0;
	while (i < nb_buckets && to_sort > 0)
	{
		count = fill_bucket(stack_a, stack_b, min + i * bucket_size, min + (i + 1) * bucket_size, to_sort);
		ft_printf("Bucket %d: min_bucket %d, max_bucket %d\n", i, min + i * bucket_size, min + (i + 1) * bucket_size);
		print_stack(*stack_b, "B after filling bucket");
		j = 0;
		if (size_a - to_sort < to_sort - count)
			while (j++ < size_a - to_sort && i != 0)
				ra(stack_a);
		else
			while (j++ < to_sort - count && i != 0)
				rra(stack_a);
		print_stack(*stack_a, "A after filling bucket");
		//rev_bubble_sort_bucket(stack_a, stack_b, count);
		simple_sort_reloaded(stack_a, stack_b, count);
		print_stack(*stack_a, "A after sorting bucket");
		j = 0;
		while (j++ < count)
			ra(stack_a);
		print_stack(*stack_a, "A after rotating sorted bucket");
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
	int	min;
	int	max;
	int	bucket_size;
	int size_a;

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
	bucket_sort(stack_a, stack_b, nb_buckets, bucket_size);
	print_stack(*stack_a, "A after bucket sort");
	return (0);
}
