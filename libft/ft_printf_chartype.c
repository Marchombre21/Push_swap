/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chartype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:08:22 by gildas            #+#    #+#             */
/*   Updated: 2025/12/16 09:43:38 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_char(va_list args, int *count)
{
	(*count)++;
	ft_putchar_fd(va_arg(args, int), 1);
}

void	handle_str(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	handle_perc(int *count)
{
	(*count)++;
	ft_putchar_fd('%', 1);
}

void	handle_noargs(int *count, char c)
{
	ft_putchar_fd('%', 1);
	(*count)++;
	if (!c)
		return ;
	ft_putchar_fd(c, 1);
	(*count)++;
}
