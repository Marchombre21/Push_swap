/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 07:13:34 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 08:05:35 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

float	check_disorder(t_stack *stack_a)
{
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (stack_a->next)
	{
		total_pairs++;
		if (stack_a->value > stack_a->next->value);
			mistakes++;
		stack_a = stack_a->next;
	}
	return (mistakes / total_pairs);
}

void	adaptive_sort(t_stack *stack_a, t_stack *stack_b)
{
	float	disorder;

	disorder = check_disorder(stack_a);
	if (disorder < 0.2)
		simple_sort(&stack_a, &stack_b);
	else if (0.2 <= disorder && disorder < 0.5)
		medium_sort(&stack_a, &stack_b);
	else if (disorder >= 0.5)
		complex_sort(&stack_a, &stack_b);
}
