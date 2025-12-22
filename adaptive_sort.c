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
		if (stack_a->value > stack_a->next->value)
			mistakes++;
		stack_a = stack_a->next;
	}
	total_pairs++;
	return (mistakes / total_pairs);
}

void	adaptive_sort(t_stacks *stacks)
{
	float	disorder;
	int		lst_size;

	lst_size = ft_lstsize(stacks->stack_a);
	disorder = check_disorder(stacks->stack_a);
	if (disorder < 0.2 || lst_size <= 40)
	{
		stacks->strategy = "Adaptive /  O(𝑛²)";
		simple_sort(stacks);
	}
	else if ((0.2 <= disorder && disorder < 0.5 && lst_size <= 225)
		|| lst_size <= 225)
	{
		stacks->strategy = "Adaptive / O(𝑛√𝑛)";
		medium_sort(stacks);
	}
	else if (disorder >= 0.5 || lst_size > 225)
	{
		stacks->strategy = "Adaptive / O(𝑛log𝑛)";
		complex_sort(stacks);
	}
}
