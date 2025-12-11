/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/11 12:20:20 by gmach            ###   ########lyon.fr   */
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
	int	sorted;

	sorted = 1;
	if (limit == 0)
		return ;
	if (limit == 1)
		return (pa(stack_a, stack_b));
	while (a_push_limited(stack_a, stack_b, limit) != 0)
	{
		print_stack(*stack_a, "A during rev buble sort");
		print_stack(*stack_b, "B during rev buble sort");
		b_push_limited(stack_a, stack_b, limit);
		print_stack(*stack_a, "A during rev buble sort");
		print_stack(*stack_b, "B during rev buble sort");
	}
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
	size_a = ft_lstsize(*stack_a);
	to_sort = size_a;
	if (bucket_size == 0)
		bucket_size = 1;
	i = 0;
	print_stack(*stack_a, "A before bucket sort");
	while (i < nb_buckets && to_sort > 0)
	{
		j = 0;
		count = 0;
		ft_printf("to_sort %d\n", to_sort);
		while (j++ < to_sort)
		{
			rra(stack_a);
			if ((*stack_a)->value <= (min + (i + 1) * bucket_size) &&
				(*stack_a)->value >= (min + i * bucket_size))
			{
				pb(stack_a, stack_b);
				count++;
			}
		}
		ft_printf("count %d\n", count);
		j = 0;
		print_stack(*stack_a, "A after bucket push");
		print_stack(*stack_b, "B after bucket push");
		ft_printf("min_bucket %d max_bucket %d count %d\n",
			(min + i * bucket_size), (min + (i + 1) * bucket_size), count);
		rev_bubble_sort_bucket(stack_a, stack_b, count);
		print_stack(*stack_a, "A after bucket sort");
		j = 0;
		while (j++ < size_a - to_sort)
			rra(stack_a);
		print_stack(*stack_a, "A after rra");
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
