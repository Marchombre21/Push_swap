/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:35:06 by bfitte            #+#    #+#             */
/*   Updated: 2025/12/20 15:14:29 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_error(t_stacks *stacks)
{
	ft_lstclear(&stacks->stack_a);
	ft_lstclear(&stacks->stack_b);
	ft_printf("Malloc error\n", 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief Sort the array so that we can retrieve the indexes later.
 * @param tab The array
 * @param size Size of the array
 */
void	sort_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_order	*ft_lstnew_ps(int value)
{
	t_order	*new_node;

	new_node = malloc(sizeof(t_order));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	check_order(t_stack *a, int *array, int size)
{
	t_order	*lists;
	t_order	*new_node;
	int		i;

	lists = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew_ps(array[i]);
		
	}

}

void	create_array(t_stack *a, int size)
{
	int		*array;
	int		i;
	t_stack	*b;

	array = ft_calloc(size + 1, sizeof(int));
	if (!array)
		return ;
	b = a;
	i = 0;
	while (a)
	{
		array[i++] = a->value;
		a = a->next;
	}
	sort_array(array, size);
	check_order(a, array, size);
}