/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:58:46 by gmach             #+#    #+#             */
/*   Updated: 2025/12/18 10:52:59 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
// #include "ft_push_swap_bonus.h"

void	add_node(int value, t_stack **stack_a)
{
	t_stack	*new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
	{
		ft_lstclear(stack_a);
		return ;
	}
	ft_lstadd_back(stack_a, new_node);
}

/**
 * @brief Check if the argument contain just digits and is within the limits of
 * int type.
 */
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
	ft_lstclear(&stack_a);
	ft_printf("Error\n", 2);
	return (stack_a);
}

/**
 * @brief Add new node to the chained list if the argument passed all tests.
 * @param nb_input Argc
 * @param numbers Argv
 */
t_stack	*parse_input(int nb_input, char **numbers)
{
	int		i;
	t_stack	*stack_a;
	int		value;

	stack_a = NULL;
	i = 0;
	while (i < nb_input)
	{
		if (check_input(numbers[i]) == 1)
			i = -1;
		else
		{
			value = ft_atoi(numbers[i]);
			if (check_duplicate(value, stack_a) == 1)
				i = -1;
			else
				add_node(value, &stack_a);
		}
		if (i == -1)
			return (handle_error(stack_a));
		i++;
	}
	return (stack_a);
}
