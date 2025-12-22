/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:07:25 by gmach             #+#    #+#             */
/*   Updated: 2025/12/22 10:17:01 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

static t_stack	*init(t_stacks *stacks, int *min, int *max, t_stack *to_sort_lst)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(stacks->stack_a);
	to_sort_lst = lf_next(stacks, to_sort_lst);
	pb(stacks);
	*min = (stacks->stack_b)->value;
	*max = (stacks->stack_b)->value;
	return (to_sort_lst);
}

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

static void	exec(t_stacks *stacks, t_stack *to_sort_lst, int to_sort)
{
	int		min_b;
	int		max_b;

	min_b = 0;
	max_b = 0;
	to_sort_lst = init(stacks, &min_b, &max_b, to_sort_lst);
	while (to_sort - 1 > 0)
	{
		to_sort_lst = lf_next(stacks, to_sort_lst);
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
	t_stack	*to_sort_lst;
	int		to_sort;

	size_a = ft_lstsize(stacks->stack_a);
	min = find_min(stacks->stack_a, size_a);
	max = find_max(stacks->stack_a, size_a);
	to_sort_lst = pre_sorted_list(stacks, find_min(stacks->stack_a, size_a));
	if (ft_lstsize(to_sort_lst) == 0)
	{
		rot_top(get_ops(stacks, 'a'), min, stacks);
		return (0);
	}
	to_sort = size_a - ft_lstsize(to_sort_lst);
	exec(stacks, to_sort_lst, to_sort);
	refill_a(stacks, min, max);
	return (0);
}
