/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:12:09 by gmach             #+#    #+#             */
/*   Updated: 2025/12/10 11:29:52 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"



int	bucket_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	sorted;
	t_stack	**buckets;

	size = ft_lstsize(*stack_a);
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
