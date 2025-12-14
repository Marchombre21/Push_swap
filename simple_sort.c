/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/14 14:36:53 by gmach            ###   ########lyon.fr   */
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

void	rotate_b_to_min(t_stack **stack_b, int target, int size_b)
{
	int count;

	count = count_nodes_until_value(*stack_b, target);
	if (count <= size_b / 2)
		while (size_b > 0 && (ft_lstlast(*stack_b))->value != target)
		{
			rb(stack_b);
			size_b--;
		}
	else
		while (size_b > 0 && (ft_lstlast(*stack_b))->value != target)
		{
			rrb(stack_b);
			size_b--;
		}
}

void	rotate_b_to_max(t_stack **stack_b, int target, int size_b)
{
	int count;

	count = count_nodes_until_value(*stack_b, target);
	if (count <= size_b / 2)
		while (size_b > 0 && (*stack_b)->value != target)
		{
			rb(stack_b);
			size_b--;
		}
	else
		while (size_b > 0 && (*stack_b)->value != target)
		{
			rrb(stack_b);
			size_b--;
		}
}

int	count_to_spot(t_stack *stack_b, int value, int size_b)
{
	int	spot_pos;
	t_stack	*current;
	int	min_b;
	int	max_b;

	min_b = find_min(stack_b, size_b);
	max_b = find_max(stack_b, size_b);
	spot_pos = 1;
	current = stack_b;
	while (current && current->next)
	{
		if (value < current->value && value > current->next->value && !(current->value == min_b && current->next->value == max_b))
			return (spot_pos);
		spot_pos++;
		current = current->next;
	}
	return (spot_pos);
}
int	rotate_b_to_spot(t_stack **stack_b, int value, int size_b)
{
	int	spot_pos;

	spot_pos = count_to_spot(*stack_b, value, size_b);
	if (spot_pos == -1)
		return (-1);
	if (spot_pos <= size_b / 2)
		while (spot_pos-- > 0)
			rb(stack_b);
	else
		while (size_b-- > spot_pos)
			rrb(stack_b);
	return (0);
}

int	simple_sort(t_stack **stack_a, t_stack **stack_b, int limit)
{
	int	size_b;
	int	i;
	int	min_b;
	int	max_b;

	i = 0;
	if (limit <= 1)
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
	while (i++ < limit - 2)
	{
		size_b = ft_lstsize(*stack_b);
		if (size_b < 2)
			return (-1);
		// check if top a is new min b and insert accordingly
		if ((*stack_a)->value < min_b)
		{
			rotate_b_to_min(stack_b, min_b, size_b);
			pb(stack_a, stack_b);
			min_b = (*stack_b)->value;
		}
		// check if top a is new max b and insert accordingly
		else if ((*stack_a)->value > max_b)
		{
			rotate_b_to_max(stack_b, max_b, size_b);
			pb(stack_a, stack_b);
			max_b = (*stack_b)->value;
		}
		// else find the right spot by rotating B
		else
		{
			if (rotate_b_to_spot(stack_b, (*stack_a)->value, size_b) == -1)
				return (-1);
			pb(stack_a, stack_b);
		}
	}
	rotate_b_to_max(stack_b, max_b, ft_lstsize(*stack_b));;
	refill_a(stack_a, stack_b);
	return (0);
}
