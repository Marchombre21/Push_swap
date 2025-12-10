/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/10 13:17:10 by gmach            ###   ########lyon.fr   */
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

t_stack	**parse_input(int argc, char **argv)
{
	int		i;
	t_stack	**stack_a;
	t_stack	*new_node;
	int		value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			ft_lstclear(stack_a, delete_value);
			return (NULL);
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (stack_a);
}


int	main(int argc, char **argv)
{
	int	i;
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_flags flags;

	flags.adaptative = 1;
	i = 1;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	while (argv[i][0] == '-' && argv[i][1] == '-')
		check_flags(argv[i++], &flags);
	stack_a = parse_input(argc - i + 1, &argv[i - 1]);
	if (!stack_a)
		return (1);
	if (flags.simple == 1)
		simple_sort(stack_a, stack_b);
	return (0);
}
