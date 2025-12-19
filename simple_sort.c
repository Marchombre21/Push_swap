/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/19 11:13:47 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ****************************************************	*/
/* Loop to push from stack A to stack B					*/
/* ****************************************************	*/

// int	b_loop(t_stacks *stacks, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_a)
// 	{
// 		if (!*stack_b)
// 			pb(stacks);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pb(stacks);
// 			sb(stack_b);
// 			sorted++;
// 		}
// 		else
// 			pb(stacks);
// 		j--;
// 	}
// 	return (sorted);
// }

// /* ****************************************************	*/
// /* Loop to push from stack B to stack A					*/
// /* ****************************************************	*/

// int	a_loop(t_stacks *stacks, int size)
// {
// 	int	j;
// 	int	sorted;

// 	sorted = 0;
// 	j = size;
// 	while (j > 0 || *stack_b)
// 	{
// 		if (!*stack_a)
// 			pa(stacks);
// 		else if ((*stack_a)->value < (*stack_b)->value)
// 		{
// 			pa(stacks);
// 			sa(stack_a);
// 			sorted++;
// 		}
// 		else
// 			pa(stacks);
// 		j--;
// 	}
// 	return (sorted);
// }

/* ****************************************************	*/
/* The simple sort algorithm used here is a variation	*/
/* of the bubble sort algorithm adapted for two stacks.	*/
/* ****************************************************	*/

// int	simple_sort(t_stacks *stacks)
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
// 		b_loop(stacks, size);
// 		sorted += a_loop(stacks, size);
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

static void	refill_a(t_stacks *stacks)
{
	while (stacks->stack_b)
		pa(stacks);
}

// int	rot_spot_b(t_ops s, int value, t_stacks *stacks)
// {
// 	int	i;
// 	int	spot_pos;
// 	int	size;

// 	i = 0;
// 	size = ft_lstsize(s.ptr);
// 	spot_pos = count_nodes_to_spot(s, value, size);
// 	if (spot_pos <= size / 2)
// 		while (i++ < spot_pos)
// 			s.rotate(stacks);
// 	else
// 	{
// 		spot_pos = size - spot_pos;
// 		while (i++ < spot_pos)
// 			s.rrotate(stacks);
// 	}
// 	return (spot_pos);
// }

// int	count_nodes_to_spot(t_ops s, int value, int to_sort)
// {
// 	int		spot_pos;
// 	int		min;
// 	int		max;
// 	t_stack	*current;

// 	min = find_min(s.ptr, to_sort);
// 	max = find_max(s.ptr, to_sort);
// 	spot_pos = 1;
// 	current = s.ptr;
// 	while (current && current->next)
// 	{
// 		if (s.letter == 'b')
// 		{
// 			if (value < current->value && value > current->next->value
// 				&& !(current->value == min && current->next->value == max))
// 				return (spot_pos);
// 		}
// 		else if (s.letter == 'a')
// 			if (value > current->value && value < current->next->value
// 				&& !(current->value == max && current->next->value == min))
// 				return (spot_pos);
// 		spot_pos++;
// 		current = current->next;
// 	}
// 	return (spot_pos);
// }

static int	init(t_stacks *stacks, int *min, int *max)
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

static void	exec(t_stacks *stacks, int to_sort)
{
	int		min_b;
	int		max_b;
	//t_ops	b_ops;

	min_b = 0;
	max_b = 0;
	to_sort -= init(stacks, &min_b, &max_b);
	//b_ops = get_ops(stacks, 'b');
	while (to_sort-- > 0)
	{
		if ((stacks->stack_a)->value < min_b)
		{
			rot_bottom(get_ops(stacks, 'b'), min_b, stacks);
			min_b = (stacks->stack_a)->value;
		}
		else if ((stacks->stack_a)->value > max_b)
		{
			rot_top(get_ops(stacks, 'b'), max_b, stacks);
			max_b = (stacks->stack_a)->value;
		}
		else
		{
			rot_spot(get_ops(stacks, 'b'), (stacks->stack_a)->value, stacks);
		}
		pb(stacks);
		//print_stack(stacks->stack_a, "A");
		//print_stack(stacks->stack_b, "B");
	}
}



int	simple_sort(t_stacks *stacks)
{
	int		max;
	int		size_a;

	size_a = ft_lstsize(stacks->stack_a);
	if (size_a <= 1 || !stacks->stack_a)
		return (-1);
	max = find_max(stacks->stack_a, size_a);
	exec(stacks, size_a);
	rot_top(get_ops(stacks, 'b'), max, stacks);
	refill_a(stacks);
	print_stack(stacks->stack_a, "A");
	print_stack(stacks->stack_b, "B");
	return (0);
}
