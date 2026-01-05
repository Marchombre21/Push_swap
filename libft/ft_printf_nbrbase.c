/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:10:32 by gmach             #+#    #+#             */
/*   Updated: 2026/01/05 11:45:02 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase_fd(long n, int fd, const char *base)
{
	int		lbase;

	lbase = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= lbase)
		ft_putnbrbase_fd(n / lbase, fd, base);
	ft_putchar_fd(base[n % lbase], fd);
}

void	ft_uputnbrbase_fd(unsigned long n, int fd, const char *base)
{
	unsigned int	lbase;

	lbase = ft_strlen(base);
	if (n >= lbase)
		ft_putnbrbase_fd(n / lbase, fd, base);
	ft_putchar_fd(base[n % lbase], fd);
}

size_t	ft_nbrlen(long n, size_t lbase)
{
	size_t	len;

	len = 1;
	if (n < 0)
		n = -n;
	while ((unsigned)n >= lbase)
	{
		n = n / lbase;
		len++;
	}
	return (len);
}

size_t	ft_unbrlen(unsigned long n, size_t lbase)
{
	size_t	len;

	len = 1;
	while (n >= lbase)
	{
		n = n / lbase;
		len++;
	}
	return (len);
}

char	*ft_itoabase(unsigned long n, const char *base)
{
	char	*str;
	size_t	lbase;
	size_t	len;

	lbase = ft_strlen(base);
	len = ft_unbrlen(n, lbase);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % lbase];
		n = n / lbase;
	}
	return (str);
}
