/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/18 14:17:44 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

/* Flags structure */
typedef struct s_flags
{
	int		bench_mode;
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	float	disorder;
	int		error;
}	t_flags;

/*stackserations structure*/
typedef struct s_count
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*strategy;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_stacks;

/* Stack_operations structure */
typedef struct s_ops
{
	char	letter;
	t_stack	*ptr;
	void	(*rotate)(t_stacks *);
	void	(*rrotate)(t_stacks *);
	void	(*swap)(t_stacks *);
}	t_ops;

/* Bucket structure */
typedef struct s_bucket
{
	int	min;
	int	max;
	int	count;
	int	number;
}	t_bucket;

/* Push_swap operations */
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

/* Utils functions */
int		next_sqrt(int nb);
int		find_min(t_stack *stack, int size);
int		find_max(t_stack *stack, int size);
void	print_stack(t_stack *stack, char *name);
int		count_nodes_until_value(t_stack *stack, int value);
t_ops	get_ops(t_stacks *stacks, char which);
int		count_nodes_to_spot(t_ops stack, int value, int to_sort);
int		rot_top(t_ops stack, int value, t_stacks *stacks);
int		rot_bottom(t_ops stack, int value, t_stacks *stacks);
int		rot_spot(t_ops stack, int value, t_stacks *stacks);
void	add_node(int value, t_stack **stack_a);
int		check_input(char *nptr);
int		check_duplicate(int value, t_stack *stack_a);
t_stack	*handle_error(t_stack *stack_a);
t_stack	*parse_input(int nb_input, char **numbers);

/* Sort functions */
int		simple_sort(t_stacks *stacks);
void	rev_simple_sort(t_stacks *stacks, int to_sort);
int		medium_sort(t_stacks *stacks);
void	complex_sort(t_stacks *stacks);
void	adaptive_sort(t_stacks *stacks);
float	check_disorder(t_stack *stack_a);

#endif
