/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:58:46 by gmach             #+#    #+#             */
/*   Updated: 2025/12/18 09:33:18 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	delete_value(int value)
{
	(void)value;
}

void	add_node(int value, t_stack **stack_a)
{
	t_stack	*new_node;
	
	new_node = ft_lstnew(value);
	if (!new_node)
	{
		ft_lstclear(stack_a, delete_value);
		return ;
	}
	ft_lstadd_back(stack_a, new_node);
}

int	check_input(char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i])
	{
		if (!(nptr[i] <= 57 && nptr[i] >= 48))
			return (1);
		result = (result * 10 + (nptr[i] - 48)) * sign;
		if (result > INT_MAX || result < INT_MIN)
			return (1);
		result *= sign;
		i++;
	}
	return (0);
}
int	check_duplicate(int value, t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->value == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

t_stack	*handle_error(t_stack *stack_a)
{
	ft_lstclear(&stack_a, delete_value);
	ft_printf("Error\n", 2);
	return (stack_a);
}
