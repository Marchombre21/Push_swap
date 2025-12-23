/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/23 13:29:36 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_algo(t_flags *flags)
{
	if (flags->complex || flags->medium || flags->simple)
		return (1);
	return (0);
}

static int	check_flags(char *s, t_flags *flags, t_stacks *stacks)
{
	if (ft_strncmp("--simple", s, 8) == 0 && !check_algo(flags))
	{
		flags->simple = 1;
		flags->adaptive = 0;
		stacks->strategy = "Simple / O(𝑛²)";
	}
	else if (ft_strncmp("--medium", s, 8) == 0 && !check_algo(flags))
	{
		flags->medium = 1;
		flags->adaptive = 0;
		stacks->strategy = "Medium / O(𝑛√𝑛)";
	}
	else if (ft_strncmp("--complex", s, 9) == 0 && !check_algo(flags))
	{
		flags->complex = 1;
		flags->adaptive = 0;
		stacks->strategy = "Complex / O(𝑛log𝑛)";
	}
	else if (ft_strncmp("--adaptive", s, 10) == 0 && !check_algo(flags))
		flags->adaptive = 1;
	else if (ft_strncmp("--bench", s, 7) == 0)
		flags->bench_mode = 1;
	else
		return (1);
	return (0);
}

static void	dispatch(t_flags *flags, t_stacks *stacks)
{
	flags->disorder = check_disorder(stacks->stack_a);
	if (ft_lstsize(stacks->stack_a) <= 1)
		return ;
	if (flags->simple)
		simple_sort(stacks);
	else if (flags->medium)
		medium_sort(stacks);
	else if (flags->complex)
		complex_sort(stacks);
	else if (flags->adaptive)
		adaptive_sort(stacks);
	if (flags->bench_mode)
	{
		ft_printf("disorder:	%f%%\n", 2, (flags->disorder * 100));
		ft_printf("strategy:	%s\n", 2, stacks->strategy);
		ft_printf("total_ops:	%d\n", 2, stacks->total);
		ft_printf("sa: %d sb: %d ss: %d pa: %d pb: %d\n", 2,
			stacks->sa, stacks->sb, stacks->ss, stacks->pa,
			stacks->pb);
		ft_printf("ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 2,
			stacks->ra, stacks->rb, stacks->rr, stacks->rra,
			stacks->rrb, stacks->rrr);
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_flags		flags;
	t_stacks	stacks;

	ft_bzero(&flags, sizeof(t_flags));
	ft_bzero(&stacks, sizeof(t_stacks));
	flags.adaptive = 1;
	i = 1;
	if (argc < 2)
		return (1);
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (check_flags(argv[i++], &flags, &stacks) == 1)
		{
			ft_printf("Error\n", 2);
			return (1);
		}
	}
	while (argv[i])
		parse_input(ft_split((const char *)argv[i++], ' '), &stacks);
	dispatch(&flags, &stacks);
	ft_lstclear(&stacks.stack_a);
	return (0);
}
