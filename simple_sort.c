/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/10 11:33:17 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	b_loop(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	j;
	int	sorted;

	sorted = 0;
	j = size;
	while (j > 0)
	{
		if (!*stack_b)
			pb(stack_a, stack_b);
		else if (*stack_a < *stack_b)
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

int	a_loop(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	j;
	int	sorted;

	sorted = 0;
	j = size;
	while (j > 0)
	{
		if (!*stack_a)
			pa(stack_a, stack_b);
		else if (*stack_b < *stack_a)
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

int	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int 	size;
	int		sorted;

	sorted = 1;
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return (-1);
	while (sorted != 0)
	{
		sorted = 0;
		sorted +=b_loop(stack_a, stack_b, size);
		sorted +=a_loop(stack_a, stack_b, size);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = ft_lstnew(10);
// 	ft_lstadd_back(&stack_a, ft_lstnew(-5));
// 	ft_lstadd_back(&stack_a, ft_lstnew(6));
// 	ft_lstadd_back(&stack_a, ft_lstnew(3));
// 	stack_b = NULL;
// 	simple_sort(&stack_a, &stack_b);
// 	while (stack_a)
// 	{
// 		printf("%d\n", stack_a->value);
// 		stack_a = stack_a->next;
// 	}
// 	return (0);
// }

