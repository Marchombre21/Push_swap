/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_presorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:58:32 by gmach             #+#    #+#             */
/*   Updated: 2025/12/20 17:39:20 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	free_all_lists(t_stack **lists, int list_count)
{
	int	i;

	if (!lists)
		return ;
	i = 0;
	while (i < list_count)
	{
		if(lists[i])
			ft_lstclear(&lists[i]);
		i++;
	}
	free(lists);
}

static t_stack	*find_valid_lists(int value, t_stack **lists, int list_count)
{
	int		i;
	t_stack	*cur;
	t_stack	*i_lists;
	t_stack	*new_node;

	i = 0;
	i_lists = NULL;
	while (i < list_count && lists[i])
	{
		cur = lists[i];
		while (cur && cur->next)
			cur = cur->next;
		if (cur && cur->value < value)
		{
			new_node = ft_lstnew(i);
			if (!new_node)
			{
				ft_lstclear(&i_lists);
				return (NULL);
			}
			ft_lstadd_back(&i_lists, new_node);
		}
		i++;
	}
	return (i_lists);
}

static t_stack	*create_new_list(int value, int min, t_stacks *stacks, t_stack **lists, int list_count)
{
	t_stack	*new;
	t_stack	*second;

	new = ft_lstnew(min);
	if (!new)
	{
		free_all_lists(lists, list_count);
		exit_error(stacks);
	}
	second = ft_lstnew(value);
	if (!second)
	{
		free(new);
		free_all_lists(lists, list_count);
		exit_error(stacks);
	}
	new->next = second;
	return (new);
}

static int	add_to_lists(int value, t_stack *i_lists, t_stack **lists)
{
	t_stack	*cur;
	t_stack *new_node;

	cur = i_lists;
	while (cur)
	{
		new_node = ft_lstnew(value);
		if (!new_node)
			return (0);
		ft_lstadd_back(&lists[cur->value], new_node);
		cur = cur->next;
	}
	return (1);
}

static t_stack	*find_best_list(t_stack **lists, int list_count)
{
	int		i;
	int		size;
	int		best_size;
	int		best_index;

	i = 0;
	best_size = 0;
	best_index = 0;
	while (lists[i] && i < list_count)
	{
		size = ft_lstsize((t_stack *)lists[i]);
		if (size > best_size)
		{
			best_size = size;
			best_index = i;
		}
		i++;
	}
	return (lists[best_index]);
}
#include <stdio.h>
t_stack	*pre_sorted_list(t_stacks *stacks, int min)
{
	t_stack	*cur;
	t_stack	**lists;
	t_stack	*i_lists;
	t_stack *res;
	int		list_count;

	lists = ft_calloc(sizeof(t_stack *), (ft_lstsize(stacks->stack_a) + 1));
	if (!lists)
		exit_error(stacks);
	cur = stacks->stack_a;
	if (ft_lstlast(cur)->value != min)
	{
		while (cur->value != min && cur)
			cur = cur->next;
		cur = cur->next;
	}
	list_count = 0;
	while (cur->value != min)
	{
		i_lists = find_valid_lists(cur->value, lists, list_count);
		if (!i_lists)
		{
			lists[list_count] = create_new_list(cur->value, min, stacks, lists, list_count);
			list_count++;
		}
		else
		{
			add_to_lists(cur->value, i_lists, lists);
			// {
			// 	ft_lstclear(&i_lists);
			// 	free_all_lists(lists, list_count);
			// 	exit_error(stacks);
			// }
			//ft_lstclear(&i_lists);
		}
		if (cur->next)
			cur = cur->next;
		else
			cur = stacks->stack_a;
	}
	res = find_best_list(lists, list_count);
	//free_all_lists(lists, list_count);
	return (res);
}

// int main(int argc, char **argv)
// {
// 	t_stack *pre_sorted;
// 	t_stacks	stacks;

// 	stacks.stack_a = parse_input(argc - 1, &argv[1]);
// 	stacks.stack_b = NULL;
// 	int min = find_min(stacks.stack_a, ft_lstsize(stacks.stack_a));
// 	int max = find_max(stacks.stack_a, ft_lstsize(stacks.stack_a));
// 	pre_sorted = pre_sorted_list(&stacks, min, max);
// 	print_stack(pre_sorted, "Pre-sorted list");
// 	return (0);
// }
