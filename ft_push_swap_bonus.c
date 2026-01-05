/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2026/01/05 10:38:53 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_sort(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/**
 * @brief Applie the operation found in the list to the list of numbers.
 * @param ope The operation.
 * @param stacks Contain list of numbers to be sorted.
 */
void	perform_operations(char *ope, t_stacks *stacks, int size_ope, char *lst)
{
	if (ft_strncmp(ope, "pa", size_ope) == 0)
		pa(stacks);
	else if (ft_strncmp(ope, "pb", size_ope) == 0)
		pb(stacks);
	else if (ft_strncmp(ope, "sa", size_ope) == 0)
		sa(stacks);
	else if (ft_strncmp(ope, "sb", size_ope) == 0)
		sb(stacks);
	else if (ft_strncmp(ope, "ss", size_ope) == 0)
		ss(stacks);
	else if (ft_strncmp(ope, "ra", size_ope) == 0)
		ra(stacks);
	else if (ft_strncmp(ope, "rb", size_ope) == 0)
		rb(stacks);
	else if (ft_strncmp(ope, "rr", size_ope) == 0)
		rr(stacks);
	else if (ft_strncmp(ope, "rra", size_ope) == 0)
		rra(stacks);
	else if (ft_strncmp(ope, "rrb", size_ope) == 0)
		rrb(stacks);
	else if (ft_strncmp(ope, "rrr", size_ope) == 0)
		rrr(stacks);
	else
		exit_bonus(stacks, lst, ope);
}

/**
 * @brief Find the first newline in list, get the previous word,
 * send him to the dispatch function, then update list by
 * remove the previous word until the list is empty.
 * @param list String which contain all instructions followed by newline
 * @param stacks Contain list of numbers to be sorted.
 */
void	reading_list(char *list, t_stacks *stacks)
{
	char	*ope;
	char	*lst_temp;
	int		index_n;

	lst_temp = list;
	index_n = ft_strchr((const char *)lst_temp, '\n');
	while (lst_temp && index_n != -1)
	{
		ope = ft_substr((const char *)lst_temp, 0, (size_t)index_n);
		if (!ope)
		{
			free(list);
			exit_malloc(stacks);
		}
		perform_operations(ope, stacks, ft_strlen((const char *)ope), list);
		free(ope);
		lst_temp = lst_temp + (index_n + 1);
		index_n = ft_strchr((const char *)lst_temp, '\n');
	}
}

/**
 * @brief Read all instructions displayed on the stdout and
 * record them in list_ope.
 */
char	*reading_ope(void)
{
	int		read_bytes;
	char	*list_ope;
	char	buffer[51];

	list_ope = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(0, buffer, 50);
		if (read_bytes == -1)
		{
			free(list_ope);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		list_ope = ft_strjoin((const char *)list_ope, (const char *)buffer);
	}
	return (list_ope);
}

int	main(int argc, char **argv)
{
	char		*list_ope;
	t_stacks	stacks;
	int			i;
	if (argc < 2)
		return (1);

	i = 1;
	ft_bzero(&stacks, sizeof(t_stacks));
	while (argv[i])
		parse_input(ft_split((const char *)argv[i++], ' '), &stacks);
	list_ope = reading_ope();
	reading_list(list_ope, &stacks);
	free(list_ope);
	list_ope = NULL;
	if (check_sort(stacks.stack_a) == 0 && !stacks.stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stacks.stack_a);
	ft_lstclear(&stacks.stack_b);
	return (0);
}
