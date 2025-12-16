/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/16 15:02:51 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ****************************************************	*/
/* Loop to push from stack A to stack B					*/
/* ****************************************************	*/

// int	b_loop(t_count *count_op, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_a)
// 	{
// 		if (!*stack_b)
// 			pb(count_op);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(count_op);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(count_op);
// 		j--;
// 	}
// 	return (sorted);
// }

// /* ****************************************************	*/
// /* Loop to push from stack B to stack A					*/
// /* ****************************************************	*/

// int	a_loop(t_count *count_op, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_b)
// 	{
// 		if (!*stack_a)
// 			pa(count_op);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(count_op);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(count_op);
// 		j--;
// 	}
// 	return (sorted);
// }

/* ****************************************************	*/
/* The simple sort algorithm used here is a variation	*/
/* of the bubble sort algorithm adapted for two stacks.	*/
/* ****************************************************	*/

// int	simple_sort(t_count *count_op)
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
// 		b_loop(count_op, size);
// 		sorted += a_loop(count_op, size);
// 	}
// 	return (0);
// }

// void	rotate_b_to_min(t_stack **stack_b, int target, int size_b)
// {
// 	int count;

// 	count = count_nodes_until_value(*stack_b, target);
// 	if (count <= size_b / 2)
// 		while (size_b > 0 && (ft_lstlast(*stack_b))->value != target)
// 		{
// 			rb(stack_b);
// 			size_b--;
// 		}
// 	else
// 		while (size_b > 0 && (ft_lstlast(*stack_b))->value != target)
// 		{
// 			rrb(stack_b);
// 			size_b--;
// 		}
// }

// void	rotate_b_to_max(t_stack **stack_b, int target, int size_b)
// {
// 	int count;

// 	count = count_nodes_until_value(*stack_b, target);
// 	if (count <= size_b / 2)
// 		while (size_b > 0 && (*stack_b)->value != target)
// 		{
// 			rb(stack_b);
// 			size_b--;
// 		}
// 	else
// 		while (size_b > 0 && (*stack_b)->value != target)
// 		{
// 			rrb(stack_b);
// 			size_b--;
// 		}
// }

// int	count_to_spot(t_stack *stack_b, int value, int size_b)
// {
// 	int	spot_pos;
// 	t_stack	*current;
// 	int	min_b;
// 	int	max_b;

// 	min_b = find_min(stack_b, size_b);
// 	max_b = find_max(stack_b, size_b);
// 	spot_pos = 1;
// 	current = stack_b;
// 	while (current && current->next)
// 	{
// 		if (value < current->value && value > current->next->value
// 			&& !(current->value == min_b && current->next->value == max_b))
// 			return (spot_pos);
// 		spot_pos++;
// 		current = current->next;
// 	}
// 	return (spot_pos);
// }
// int	rotate_b_to_spot(t_stack **stack_b, int value, int size_b)
// {
// 	int	spot_pos;

// 	spot_pos = count_to_spot(*stack_b, value, size_b);
// 	if (spot_pos == -1)
// 		return (-1);
// 	if (spot_pos <= size_b / 2)
// 		while (spot_pos-- > 0)
// 			rb(stack_b);
// 	else
// 		while (size_b-- > spot_pos)
// 			rrb(stack_b);
// 	return (0);
// }

static void	refill_a(t_count *stacks)
{
	while (stacks->stack_b)
		pa(stacks);
}

static int	init(t_count *stacks, int *min, int *max)
{
	pb(stacks);
	if ((stacks->stack_a)->value > (stacks->stack_b)->value)
	{
		*min = (stacks->stack_b)->value;
		pb(stacks);
		*max = (stacks->stack_b)->value;
	}
	else
	{
		*min = (stacks->stack_a)->value;
		*max = (stacks->stack_b)->value;
		pb(stacks);
	}
	return (2);
}

static void	exec(t_count *stacks, int *min_b, int *max_b)
{
	int		i;
	int		to_sort;
	t_ops	b_ops;

	i = 0;
	to_sort = ft_lstsize(stacks->stack_a);
	b_ops = get_ops(stacks, 'b');
	while (i++ < to_sort)
	{
		if ((stacks->stack_a)->value < *min_b)
		{
			rot_top(b_ops, *max_b, stacks);
			*min_b = (stacks->stack_a)->value;
		}
		else if ((stacks->stack_a)->value > *max_b)
		{
			rot_top(b_ops, *max_b, stacks);
			*max_b = (stacks->stack_a)->value;
		}
		else
			rot_spot(b_ops, (stacks->stack_a)->value, stacks);
		pb(stacks);
	}
}

int	simple_sort(t_count *stacks, int to_sort)
{
	int		min_b;
	int		max_b;
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = &stacks->stack_a;
	stack_b = &stacks->stack_b;
	if (to_sort <= 1 || !*stack_a || ft_lstsize(*stack_a) < to_sort)
		return (-1);
	min_b = 0;
	max_b = 0;
	init(stacks, &min_b, &max_b);
	exec(stacks, &min_b, &max_b);
	rot_top(get_ops(stacks, 'b'), max_b, stacks);
	refill_a(stacks);
	return (0);
}
