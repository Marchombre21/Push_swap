/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/22 07:54:49 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_presorted(int value, t_stack *pre_sorted)
{
	t_stack	*current;

	current = pre_sorted;
	while (current)
	{
		if (value == current->value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	refill_a(t_stacks *stacks, int min, int max)
{
	int	min_a;
	int	max_a;
	int	size_a;

	if (!stacks->stack_b)
		return ;
	while (stacks->stack_b)
	{
		size_a = ft_lstsize(stacks->stack_a);
		min_a = find_min(stacks->stack_a, size_a);
		max_a = find_max(stacks->stack_a, size_a);
		if ((stacks->stack_b)->value == min)
			rot_top(get_ops(stacks, 'a'), min_a, stacks);
		else if ((stacks->stack_b)->value == max)
			rot_bottom(get_ops(stacks, 'a'), max_a, stacks);
		else
			rot_spot(get_ops(stacks, 'a'), (stacks->stack_b)->value, stacks);
		pa(stacks);
	}
	rot_top(get_ops(stacks, 'a'), min, stacks);
}

static int	init(t_stacks *stacks, int *min, int *max, t_stack *pre_sorted)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(stacks->stack_a);
	while (i++ < size && is_presorted((stacks->stack_a)->value, pre_sorted))
		ra(stacks);
	pb(stacks);
	*min = (stacks->stack_b)->value;
	*max = (stacks->stack_b)->value;
	return (1);
}

// static void	go_to_not_presorted(t_stacks *stacks, t_stack *pre_sorted)
// {
// 	int	size;
// 	int	i;
// 	int next_value;
// 	t_stack *current;

// 	i = 0;
// 	size = ft_lstsize(stacks->stack_a);
// 	current = stacks->stack_a;

// 	count_nodes_to_spot()
// 	while (i++ < size && is_presorted((stacks->stack_a)->value, pre_sorted))
// 		ra(stacks);
// }

static void	dispatch_rot(t_stacks *stacks, int *min_b, int *max_b)
{
	t_ops	b_ops;

	b_ops = get_ops(stacks, 'b');
		if ((stacks->stack_a)->value < (*min_b))
		{
			rot_bottom(b_ops, *min_b, stacks);
			(*min_b) = (stacks->stack_a)->value;
		}
		else if ((stacks->stack_a)->value > (*max_b))
		{
			rot_top(b_ops, *max_b, stacks);
			(*max_b) = (stacks->stack_a)->value;
		}
		else
			rot_spot(b_ops, (stacks->stack_a)->value, stacks);
}

static void	exec(t_stacks *stacks, t_stack *pre_sorted, int to_sort)
{
	int		min_b;
	int		max_b;
	

	min_b = 0;
	max_b = 0;
	if (init(stacks, &min_b, &max_b, pre_sorted) == 0)
		return ;
	while (to_sort - 1 > 0)
	{
		// go_to_not_presorted(stacks, pre_sorted);
		if (is_presorted((stacks->stack_a)->value, pre_sorted))
		{
			ra(stacks);
			continue ;
		}
		dispatch_rot(stacks, &min_b, &max_b);
		pb(stacks);
		to_sort--;
	}
}

/**
 * @brief Sorts a stack with an insertion sorting algorithm.
 */
int	simple_sort(t_stacks *stacks)
{
	int		min;
	int		max;
	int		size_a;
	t_stack	*pre_sorted;
	int		to_sort;

	size_a = ft_lstsize(stacks->stack_a);
	min = find_min(stacks->stack_a, size_a);
	max = find_max(stacks->stack_a, size_a);
	// print_stack(stacks->stack_a, "Initial stack A");
	pre_sorted = pre_sorted_list(stacks, find_min(stacks->stack_a, size_a));
	if (ft_lstsize(pre_sorted) == size_a)
	{
		rot_top(get_ops(stacks, 'a'), min, stacks);
		// print_stack(pre_sorted, "Pre-sorted list");
		return (0);
	}
	to_sort = size_a - ft_lstsize(pre_sorted);
	// print_stack(pre_sorted, "Pre-sorted list");
	exec(stacks, pre_sorted, to_sort);
	refill_a(stacks, min, max);
	// print_stack(stacks->stack_a, "Sorted stack A");
	return (0);
}
