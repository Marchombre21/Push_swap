/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:14:40 by bfitte/gmac       #+#    #+#             */
/*   Updated: 2025/12/09 09:50:44 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <ft_printf.h>
# include <libft.h>

typedef struct s_stack
{
	int	value;
	struct s_stack	*next;
}	t_stack;

typedef struct  s_flags
{
	int	bench_mode;
	int	simple;
	int	medium;
	int	complex;
	int	adaptative;
	int	disorder;
	int	error;
}	t_flags;


#endif
