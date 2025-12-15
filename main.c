/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 08:03:18 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_flags(char *s, t_flags *flags)
{
	if (ft_strncmp("--simple", s, 8) == 0)
	{
		flags->simple = 1;
		flags->adaptative = 0;
	}
	else if(ft_strncmp("--medium", s, 8) == 0)
	{
		flags->medium = 1;
		flags->adaptative = 0;
	}
	else if(ft_strncmp("--complex", s, 9) == 0)
	{
		flags->complex = 1;
		flags->adaptative = 0;
	}
	else if(ft_strncmp("--bench", s, 7) == 0)
		flags->bench_mode = 1;
}

void	delete_value(int value)
{
	(void)value;
}

t_stack	*parse_input(int nb_input, char **numbers)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*new_node;
	int		value;

	stack_a = NULL;
	i = 0;
	while (i < nb_input)
	{
		value = ft_atoi(numbers[i]);
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			ft_lstclear(&stack_a, delete_value);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags flags;

	ft_bzero(&flags, sizeof(t_flags));
	flags.adaptative = 1;
	i = 1;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	// ft_printf("check\n");
	while (argv[i][0] == '-' && argv[i][1] == '-')
		check_flags(argv[i++], &flags);
	// ft_printf("Flags - simple: %d, medium: %d, complex: %d, adaptative: %d, bench_mode: %d\n",
	// 	flags.simple, flags.medium, flags.complex, flags.adaptative, flags.bench_mode);
	stack_a = parse_input(argc - i, &argv[i]);
	if (!stack_a)
		return (1);
	if (flags.simple)
		simple_sort(&stack_a, &stack_b);
	else if (flags.medium)
		medium_sort(&stack_a, &stack_b);
	else if (flags.complex)
		complex_sort(&stack_a, &stack_b);
	else if (flags.adaptative)
		adaptative_sort(stack_a, stack_b);
	// ft_printf("Stack A:\n");
	// t_stack *current = stack_a;
	// while (current != NULL)
	// {
	// 	ft_printf("%d\n", current->value);
	// 	current = current->next;
	// }
	ft_lstclear(&stack_a, delete_value);
	return (0);
}
