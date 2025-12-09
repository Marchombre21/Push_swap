/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:37:40 by gmach             #+#    #+#             */
/*   Updated: 2025/11/28 09:55:31 by gmach            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);

size_t	ft_nbrlen(long n, size_t lbase);
size_t	ft_unbrlen(unsigned long n, size_t lbase);
char	*ft_itoabase(unsigned long n, const char *base);
void	ft_putnbrbase_fd(long n, int fd, const char *base);
void	ft_uputnbrbase_fd(unsigned long n, int fd, const char *base);

void	handle_int(va_list args, int *count);
void	handle_unsint(va_list args, int *count);
void	handle_hex(va_list args, int *count, char *base);
void	handle_ptr(va_list args, int *count, const char *base);

void	handle_char(va_list args, int *count);
void	handle_str(va_list args, int *count);
void	handle_perc(int *count);
void	handle_noargs(int *count, char c);

#endif
