/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2026/01/05 11:28:50 by gmach            ###   ########lyon.fr   */
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
typedef struct s_stacks
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

/* Lists structure for pre_sorted */
typedef struct s_lists
{
	t_stack		**lists;
	t_stack		*i_lists;
	t_stacks	*stacks;
	int			list_count;
}	t_lists;

/**
 * @brief Operations structure for stack manipulations.
 * @param letter Identifier for the stack ('a' or 'b').
 * @param ptr Pointer to the stack.
 * @param rotate Function pointer to the rotate operation.
 * @param rrotate Function pointer to the reverse rotate operation.
 * @param swap Function pointer to the swap operation.
 */
typedef struct s_ops
{
	char	letter;
	t_stack	*ptr;
	void	(*rotate)(t_stacks *);
	void	(*rrotate)(t_stacks *);
	void	(*swap)(t_stacks *);
}	t_ops;

/**
 * @brief Bucket structure for bucket sort algorithm.
 * @param min Minimum value in the bucket.
 * @param max Maximum value in the bucket.
 * @param count Number of elements in the bucket.
 * @param number Bucket identifier.
 */
typedef struct s_bucket
{
	float	min;
	float	max;
	int		count;
	int		number;
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
int		find_max_complex(t_stack *a);
void	print_stack(t_stack *stack, char *name);
t_ops	get_ops(t_stacks *stacks, char which);
int		count_nodes_until_value(t_stack *stack, int value);
int		count_nodes_to_spot(t_ops stack, int value, int to_sort);
int		rot_top(t_ops stack, int value, t_stacks *stacks);
int		rot_bottom(t_ops stack, int value, t_stacks *stacks);
int		rot_spot(t_ops stack, int value, t_stacks *stacks);
void	add_node(int value, t_stack **stack_a);
int		check_input(char *nptr);
int		check_duplicate(int value, t_stack *stack_a);
void	parse_input(char **numbers, t_stacks *stacks);
void	exit_malloc(t_stacks *stacks);
t_stack	*pre_sorted_list(t_stacks *stacks, int min);
int		is_presorted(int value, t_stack *pre_sorted);
t_stack	*create_new_list(int value, int min, t_lists *sorted);
int		find_max_complex(t_stack *a);
void	exit_bonus(t_stacks *stacks, char *lst, char *ope);
void	free_split(char **str);
void	free_all_lists(t_lists *sorted);

/* Sort functions */
void	micro_sort(t_stacks *stacks);
void	simple_sort(t_stacks *stacks);
void	medium_sort(t_stacks *stacks);
void	complex_sort(t_stacks *stacks);
void	adaptive_sort(t_stacks *stacks);
float	check_disorder(t_stack *stack_a);

#endif
