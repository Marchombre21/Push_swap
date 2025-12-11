/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/11 17:55:27 by gmach            ###   ########lyon.fr   */
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

void	refill_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	int	i;
	int	min_b;
	int	max_b;

	size_a = ft_lstsize(*stack_a);
	i = 0;
	if (size_a <= 1)
		return (-1);
	//init 2 first terms in B
	pb(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_b)->value)
	{
		min_b = (*stack_b)->value;
		pb(stack_a, stack_b);
		max_b = (*stack_b)->value;
	}
	else
	{
		min_b = (*stack_a)->value;
		max_b = (*stack_b)->value;
		pb(stack_a, stack_b);
		sb(stack_b);
	}
	while (*stack_a)
	{
		size_b = ft_lstsize(*stack_b);
		// if top a < min b
		if ((*stack_a)->value < min_b)
		{
			set_min_b((*stack_a)->value, &min_b);
			pb(stack_a, stack_b);
			min_b = (*stack_b)->value;
			print_stack(*stack_b, "B after pb");
		}
		// else if top a > max b
		else if ((*stack_a)->value > max_b)
		{
			set_max_b((*stack_a)->value, &max_b);
			pb(stack_a, stack_b);
			max_b = (*stack_b)->next->value;
			print_stack(*stack_b, "B after pb and rb");
		}
		else if((*stack_a)->value > (*stack_b)->value && (*stack_a)->value < ft_lstlast(*stack_b)->value)
		{
			pb(stack_a, stack_b);
			print_stack(*stack_b, "B after pb");
		}
		else if ((*stack_a)->value > (*stack_b)->next->value)
		{
			pb(stack_a, stack_b);
			sb(stack_b);
			print_stack(*stack_b, "B after pb and sb");
		}
		else
		{
			while (size_b > 0 && (*stack_a)->value < (*stack_b)->value)
			{
				print_stack(*stack_a, "A");
				print_stack(*stack_b, "B");
				rb(stack_b);
				size_b--;
			}
			pb(stack_a, stack_b);
			print_stack(*stack_b, "B after pb");
		}
	}
	refill_a(stack_a, stack_b);
	return (0);
}
