/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/09 11:40:00 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_flags(char *s, t_flags *flags)
{
	if (s == "--simple")
	{
		flags->simple = 1;
		flags->adaptative = 0;
	}
	else if(s == "--medium")
	{
		flags->medium = 1;
		flags->adaptative = 0;
	}
	else if(s == "--complex")
	{
		flags->complex = 1;
		flags->adaptative = 0;
	}
	else if(s == "--bench")
		flags->bench_mode = 1;
}

int	main(int argc, char **argv)
{
	int	i;
	t_flags flags;

	flags.adaptative = 1;
	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i][0] == '-' && argv[i][1] == '-')
		check_flags(argv[i++], &flags);
	
	return (0);
}