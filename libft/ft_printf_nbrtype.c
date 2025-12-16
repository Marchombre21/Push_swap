/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:04:25 by gildas            #+#    #+#             */
/*   Updated: 2025/12/16 12:23:59 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_int(va_list args, int *count)
{
	int	n;

	n = va_arg(args, int);
	if (n < 0)
		(*count)++;
	*count += ft_nbrlen(n, 10);
	ft_putnbr_fd(n, 1);
}

void	handle_float(va_list args, int *count)
{
	double	n;
	int	i;
	int	before_float;

	i = 0;
	n = va_arg(args, double);
	before_float = (int)n;
	ft_putnbr_fd(before_float, 1);
	write(1, ".", 1);
	*count += 2;
	while (i++ < 2)
	{
		(*count)++;
		n -= before_float;
		n *= 10;
		before_float = (int)n;
		ft_putnbr_fd(before_float, 1);
	}
}

void	handle_unsint(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	*count += ft_nbrlen(n, 10);
	ft_uputnbrbase_fd(n, 1, "0123456789");
}

void	handle_hex(va_list args, int *count, char *base)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	*count += ft_nbrlen(n, ft_strlen(base));
	ft_uputnbrbase_fd(n, 1, base);
}

void	handle_ptr(va_list args, int *count, const char *base)
{
	char			*str;
	unsigned long	ptr_arg;

	ptr_arg = (unsigned long)va_arg(args, void *);
	if (ptr_arg == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
		return ;
	}
	str = ft_itoabase(ptr_arg, base);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str) + 2;
	free(str);
}
