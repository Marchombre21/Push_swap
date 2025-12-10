/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/10 16:27:17 by gmach            ###   ########lyon.fr   */
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
	if ((int)(root * root) == nb)
		return ((int)root + 1);
	return ((int)root);
}

/* ****************************************************	*/
/* Bucket sort is used here								*/
/* ****************************************************	*/

int	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	sorted;
	t_stack	**buckets;

	size = next_sqrt(ft_lstsize(*stack_a));
	if (size <= 1)
		return (-1);
	sorted = 1;
	buckets = malloc(sizeof(t_stack *) * size);
	if (!buckets)
		return (-1);
	while (sorted != 0)
	{

	}
	return (0);
}

int main(void)
{
	printf("%d\n", next_sqrt(10));
	return 0;
}
