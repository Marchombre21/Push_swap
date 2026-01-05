/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:32:08 by bfitte            #+#    #+#             */
/*   Updated: 2026/01/05 09:50:28 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_bonus(t_stacks *stacks, char *lst, char *ope)
{
	ft_lstclear(&stacks->stack_a);
	ft_lstclear(&stacks->stack_b);
	free(lst);
	free(ope);
	ft_printf("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

// void	handle_inputs(t_stacks *stacks, char **numbers)
// {
// 	int	i;
// 	int	j;
// 	int	space;

// 	space = 0;
// 	i = 0;
// 	while (numbers[i])
// 	{
// 		j = 0;
// 		while (numbers[i][j])
// 		{
// 			if (numbers[i][j] == ' ')
// 				space = 1;
// 			j++;
// 		}
// 		if (space != 0)
// 			parse_input(ft_split((const char *)numbers[i], ' '), stacks, 1);
// 		else
// 			parse_input(ft_split((const char *)numbers[i], ' '), stacks, 1);
// 		i++;
// 	}
// }
