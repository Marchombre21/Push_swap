/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:11:39 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/17 16:24:47 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

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

void	perform_operations(char *ope, t_stacks *stacks)
{
	int	size_ope;

	size_ope = ft_strlen((const char *)ope);
	if(ft_strncmp(ope, "pa", size_ope) == 0)
		pa(stacks);
	else if(ft_strncmp(ope, "pb", size_ope) == 0)
		pb(stacks);
	else if(ft_strncmp(ope, "sa", size_ope) == 0)
		sa(stacks);
	else if(ft_strncmp(ope, "sb", size_ope) == 0)
		sb(stacks);
	else if(ft_strncmp(ope, "ss", size_ope) == 0)
		ss(stacks);
	else if(ft_strncmp(ope, "ra", size_ope) == 0)
		ra(stacks);
	else if(ft_strncmp(ope, "rb", size_ope) == 0)
		rb(stacks);
	else if(ft_strncmp(ope, "rr", size_ope) == 0)
		rr(stacks);
	else if(ft_strncmp(ope, "rra", size_ope) == 0)
		rra(stacks);
	else if(ft_strncmp(ope, "rrb", size_ope) == 0)
		rrb(stacks);
	else if(ft_strncmp(ope, "rrr", size_ope) == 0)
		rrr(stacks);
}

void	reading_list(char *list, t_stacks *stacks)
{
	int	i;
	char	*ope;
	char	*lst_temp;
	int		index_n;

	i = 0;
	lst_temp = list;
	index_n = ft_strchr((const char *)lst_temp, '\n');
	while (lst_temp && index_n != -1)
	{
		ope = ft_substr((const char *)lst_temp, 0, (size_t)index_n);
		perform_operations(ope, stacks);
		lst_temp = lst_temp + (index_n + 1);
		index_n = ft_strchr((const char *)lst_temp, '\n');
	}
	if (lst_temp && index_n  != -1)
		perform_operations(lst_temp + 1, stacks);
	free((void *)list);
}

char	*reading_ope(void)
{
	int		read_bytes;
	char	*list_ope;
	char	buffer[50];
	
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
		list_ope = ft_strjoin((const char *)list_ope, (const char*)buffer);
	}
	return(list_ope);
}

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

int	main(int argc, char **argv)
{
	char	*list_ope;
	t_stacks	stacks;
	
	list_ope = reading_ope();
	ft_bzero(&stacks, sizeof(t_stacks));
	if (argc < 2)
		return (0);
	stacks.stack_a = parse_input(argc - 1, &argv[1]);
	if (!stacks.stack_a)
		return (1);
	reading_list(list_ope, &stacks);
	list_ope = NULL;
	if (check_sort(stacks.stack_a) == 0 && !stacks.stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stacks.stack_a, delete_value);
	return (0);
}
