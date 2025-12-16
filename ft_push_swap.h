/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/16 08:39:27 by bfitte/gmac      ###   ########lyon.fr   */
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
	int		bench_mode;
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	float	disorder;
	int		error;
}	t_flags;

/*Count_operations structure*/
typedef struct s_count
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*strategy;
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
}	t_count;

/* Stack_operations structure */
typedef struct s_stack_ops
{
	char	letter;
	t_stack	*ptr;
	void	(*rotate)(t_count *);
	void	(*rrotate)(t_count *);
	void	(*swap)(t_count *);
}	t_stack_ops;

/* Bucket structure */
typedef struct s_bucket
{
	int	min;
	int	max;
	int	count;
	int	number;
}	t_bucket;

/* Push_swap operations */
void	sa(t_count *count_op);
void	sb(t_count *count_op);
void	ss(t_count *count_op);
void	pa(t_count *count_op);
void	pb(t_count *count_op);
void	ra(t_count *count_op);
void	rb(t_count *count_op);
void	rr(t_count *count_op);
void	rra(t_count *count_op);
void	rrb(t_count *count_op);
void	rrr(t_count *count_op);

/* Utils functions */
int		next_sqrt(int nb);
int		find_min(t_stack *stack, int size);
int		find_max(t_stack *stack, int size);
void	print_stack(t_stack *stack, char *name);
int		count_nodes_until_value(t_stack *stack, int value);
t_stack_ops	get_stack_ops(t_count *count_op, char which);
int		count_nodes_to_spot(t_stack_ops stack, int value, int to_sort);
int		rot_top(t_stack_ops stack, int value, t_count *count_op);
int		rot_bottom(t_stack_ops stack, int value, t_count *count_op);
int		rot_spot(t_stack_ops stack, int value, t_count *count_op);

void	rel_rot_a_to_min(t_stack **stack_a, int target, int to_sort);
int		rotate_b_to_spot(t_stack **stack_b, int value, int size_b);
void	rotate_b_to_min(t_stack **stack_b, int target, int size_b);

/* Sort functions */
int		simple_sort(t_count *count_op, int size);
void	rev_simple_sort(t_count *count_op, int to_sort);
int		medium_sort(t_count *count_op);
void	complex_sort(t_count *count_op);
void	adaptive_sort(t_count *count_op);
float	check_disorder(t_stack *stack_a);

#endif
