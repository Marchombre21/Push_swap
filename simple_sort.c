/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/11 17:13:33 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ****************************************************	*/
/* Loop to push from stack A to stack B					*/
/* ****************************************************	*/

// int	b_loop(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_a)
// 	{
// 		if (!*stack_b)
// 			pb(stack_a, stack_b);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(stack_a, stack_b);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(stack_a, stack_b);
// 		j--;
// 	}
// 	return (sorted);
// }

// /* ****************************************************	*/
// /* Loop to push from stack B to stack A					*/
// /* ****************************************************	*/

// int	a_loop(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_b)
// 	{
// 		if (!*stack_a)
// 			pa(stack_a, stack_b);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(stack_a, stack_b);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(stack_a, stack_b);
// 		j--;
// 	}
// 	return (sorted);
// }

/* ****************************************************	*/
/* The simple sort algorithm used here is a variation	*/
/* of the bubble sort algorithm adapted for two stacks.	*/
/* ****************************************************	*/

// int	simple_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		size;
// 	int		sorted;

// 	sorted = 1;
// 	size = ft_lstsize(*stack_a);
// 	if (size <= 1)
// 		return (-1);
// 	while (sorted != 0)
// 	{
// 		sorted = 0;
// 		b_loop(stack_a, stack_b, size);
// 		sorted += a_loop(stack_a, stack_b, size);
// 	}
// 	return (0);
// }

int simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	j;
	int	min;

	size = ft_lstsize(*stack_a);
	i = 0;
	if (size <= 1)
		return (-1);
	pb(stack_a, stack_b);
	while (*stack_a)
	{
		if((*stack_a)->value > (*stack_b)->value)
			pb()
	}
	return (0);
}
