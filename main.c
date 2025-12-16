/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/16 13:33:34 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_flags(char *s, t_flags *flags, t_count *count_op)
{
	if (ft_strncmp("--simple", s, 8) == 0)
	{
		flags->simple = 1;
		flags->adaptive = 0;
		count_op->strategy = "Simple / O(𝑛²)";
	}
	else if(ft_strncmp("--medium", s, 8) == 0)
	{
		flags->medium = 1;
		flags->adaptive = 0;
		count_op->strategy = "Medium / O(𝑛\u221a𝑛)";
	}
	else if(ft_strncmp("--complex", s, 9) == 0)
	{
		flags->complex = 1;
		flags->adaptive = 0;
		count_op->strategy = "Complex / O(𝑛log𝑛)";
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

void	dispatch(t_flags *flags, t_count *count_op)
{
	flags->disorder = check_disorder(count_op->stack_a);
	if (flags->simple)
		simple_sort(count_op, ft_lstsize(count_op->stack_a));
	else if (flags->medium)
		medium_sort(count_op);
	else if (flags->complex)
		complex_sort(count_op);
	else if (flags->adaptive)
		adaptive_sort(count_op);
	if (flags->bench_mode)
	{
		ft_printf("disorder:	%f%%\n", 2, flags->disorder);
		ft_printf("strategy:	%s\n", 2, count_op->strategy);
		ft_printf("total_ops:	%d\n", 2, count_op->total);
		ft_printf("sa: %d sb: %d ss: %d pa: %d pb: %d\n", 2,
			 count_op->sa, count_op->sb, count_op->ss, count_op->pa,
			 count_op->pb);
		ft_printf("ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 2, 
			count_op->ra, count_op->rb, count_op->rr, count_op->rra,
			 count_op->rrb, count_op->rrr);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_flags flags;
	t_count count_op;

	ft_bzero(&flags, sizeof(t_flags));
	ft_bzero(&count_op, sizeof(t_count));
	flags.adaptive = 1;
	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i][0] == '-' && argv[i][1] == '-')
		check_flags(argv[i++], &flags, &count_op);
	count_op.stack_a = parse_input(argc - i, &argv[i]);
	if (!count_op.stack_a)
		return (1);
	dispatch(&flags, &count_op);
	// ft_printf("pa : %d\n", count_op.pa);
	// ft_printf("pb : %d\n", count_op.pb);
	// ft_printf("ra : %d\n", count_op.ra);
	// ft_printf("strat : %s\n", count_op.strategy);
	// ft_printf("disorder : %f\n", flags.disorder);
	// ft_printf("\u221a\n");
	ft_lstclear(&count_op.stack_a, delete_value);
	return (0);
}
