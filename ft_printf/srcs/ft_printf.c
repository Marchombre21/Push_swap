/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:37:37 by gmach             #+#    #+#             */
/*   Updated: 2025/11/28 11:54:04 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static void	manage_args(va_list args, const char *format, int *count)
{
	if (*format == 'c')
		handle_char(args, count);
	else if (*format == 's')
		handle_str(args, count);
	else if (*format == 'p')
		handle_ptr(args, count, "0123456789abcdef");
	else if (*format == 'd' || *format == 'i')
		handle_int(args, count);
	else if (*format == 'u')
		handle_unsint(args, count);
	else if (*format == 'x')
		handle_hex(args, count, "0123456789abcdef");
	else if (*format == 'X')
		handle_hex(args, count, "0123456789ABCDEF");
	else if (*format == '%')
		handle_perc(count);
	else
		handle_noargs(count, *format);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			manage_args(args, format, &count);
		}
		else if (*format)
		{
			ft_putchar_fd((char)*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
