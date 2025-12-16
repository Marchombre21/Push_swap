/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chartype.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:08:22 by gildas            #+#    #+#             */
/*   Updated: 2025/12/16 13:14:29 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_char(va_list args, int *count, int fd)
{
	(*count)++;
	ft_putchar_fd(va_arg(args, int), fd);
}

void	handle_str(va_list args, int *count, int fd)
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
	ft_putstr_fd(str, fd);
}

void	handle_perc(int *count, int fd)
{
	(*count)++;
	ft_putchar_fd('%', fd);
}

void	handle_noargs(int *count, char c, int fd)
{
	ft_putchar_fd('%', fd);
	(*count)++;
	if (!c)
		return ;
	ft_putchar_fd(c, fd);
	(*count)++;
}
