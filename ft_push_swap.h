/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildas <gildas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/15 11:27:56 by gildas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <ft_printf.h>
# include <libft.h>

/* Flags structure */
typedef struct s_flags
{
	int	bench_mode;
	int	simple;
	int	medium;
	int	complex;
	int	adaptative;
	int	disorder;
	int	error;
}	t_flags;

/* Stack_operations structure */
typedef struct s_stack_ops
{
	char	letter;
	t_stack	**ptr;
	void	(*rotate)(t_stack **);
	void	(*rrotate)(t_stack **);
	void	(*swap)(t_stack **);
}	t_stack_ops;

/* Push_swap operations */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Utils functions */
int		next_sqrt(int nb);
int		find_min(t_stack *stack, int size);
int		find_max(t_stack *stack, int size);
void	print_stack(t_stack *stack, char *name);
int		count_nodes_until_value(t_stack *stack, int value);
t_stack_ops	get_stack_ops(t_stack **stack, char which);
int		count_nodes_to_spot(t_stack_ops stack, int value, int to_sort);
int		rot_top(t_stack_ops stack, int value);
int		rot_bottom(t_stack_ops stack, int value);
int		rot_spot(t_stack_ops stack, int value);

void	rel_rot_a_to_min(t_stack **stack_a, int target, int to_sort);
int		rotate_b_to_spot(t_stack **stack_b, int value, int size_b);
void	rotate_b_to_min(t_stack **stack_b, int target, int size_b);

/* Sort functions */
int		simple_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	rev_simple_sort(t_stack **stack_a, t_stack **stack_b, int to_sort);
int		medium_sort(t_stack **stack_a, t_stack **stack_b);

#endif
