/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/18 10:03:45 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

/*stackserations structure*/
typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

/* Stack_operations structure */
// typedef struct s_ops
// {
// 	char	letter;
// 	t_stack	*ptr;
// 	void	(*rotate)(t_stacks *);
// 	void	(*rrotate)(t_stacks *);
// 	void	(*swap)(t_stacks *);
// }	t_ops;

// /* Bucket structure */
// typedef struct s_bucket
// {
// 	int	min;
// 	int	max;
// 	int	count;
// 	int	number;
// }	t_bucket;

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
void	add_node(int value, t_stack **stack_a);
int		check_input(char *nptr);
int		check_duplicate(int value, t_stack *stack_a);
t_stack	*handle_error(t_stack *stack_a);
int		check_sort(t_stack *stack_a);

#endif
