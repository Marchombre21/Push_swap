/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:38 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/10 17:06:52 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*merge(t_stack **lst, int half_size_two, t_stack *half_list, int half_size)
{
	int	i;
	int	size_lst;
	t_stack	*temp;

	size_lst = ft_lstsize(*lst);
	i = 0;
	while (i < size_lst)
	{
		if ((*lst)->next->value > half_list->next->value)
		{
			temp = half_list->next;
			half_list->next = temp->next;
			temp->next = (*lst)->next;
			(*lst)->next = temp;
			if (half_size == 1)
				break;
			half_size--;
		}
		else
		{
			if (half_size_two == 1)
			{
				while (half_size >= 1)
				{
					half_list = half_list->next;
					half_size--;
				}
			}
			half_size_two--;
		}
		*lst = (*lst)->next;
	}
	return (half_list);
}

t_stack	*sort(t_stack *lst, int size)
{
	int	half_size;
	int	half_size_two;
	t_stack	*half_list;

	half_size = size /2;
	half_size_two = size - half_size;
	if (half_size_two >= 2)
	{
		half_list = sort(lst, half_size_two);
		if (half_size >= 2)
			sort(half_list, half_size);
	}
	else
		half_list = lst->next;
	half_list = merge(&lst, half_size_two, half_list, half_size);
	return (half_list);
}

void	complex_sort(t_stack **a)
{
	int	size_list;

	size_list = ft_lstsize(*a);
	sort(*a, size_list);
}
