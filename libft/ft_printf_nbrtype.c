/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:04:25 by gildas            #+#    #+#             */
/*   Updated: 2025/12/22 14:50:29 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_int(va_list args, int *count, int fd)
{
	int	n;

	n = va_arg(args, int);
	if (n < 0)
		(*count)++;
	*count += ft_nbrlen(n, 10);
	ft_putnbr_fd(n, fd);
}

void	handle_float(va_list args, int *count, int fd)
{
	double	n;
	int		i;
	int		before_float;

	i = 0;
	n = va_arg(args, double);
	before_float = (int)n;
	ft_putnbr_fd(before_float, fd);
	write(fd, ".", 1);
	*count += 2;
	while (i++ < 2)
	{
		(*count)++;
		n -= before_float;
		n *= 10;
		before_float = (int)n;
		ft_putnbr_fd(before_float, fd);
	}
}

void	handle_unsint(va_list args, int *count, int fd)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	*count += ft_nbrlen(n, 10);
	ft_uputnbrbase_fd(n, fd, "0123456789");
}

void	handle_hex(va_list args, int *count, char *base, int fd)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	*count += ft_nbrlen(n, ft_strlen(base));
	ft_uputnbrbase_fd(n, fd, base);
}

void	handle_ptr(va_list args, int *count, const char *base, int fd)
{
	char			*str;
	unsigned long	ptr_arg;

	ptr_arg = (unsigned long)va_arg(args, void *);
	if (ptr_arg == 0)
	{
		ft_putstr_fd("(nil)", fd);
		*count += 5;
		return ;
	}
	str = ft_itoabase(ptr_arg, base);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(str, fd);
	*count += ft_strlen(str) + 2;
	free(str);
}
