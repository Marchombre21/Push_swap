/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:09:28 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/11 08:09:28 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// void	ft_putnbr_fd(int n, int fd);

// // int	main(void)
// // {
// // 	int	fd = open("test.c", O_WRONLY);
// // 	if (fd == -1)
// // 		printf("ERROR");
// // 	int    i = -5148;
// // 	ft_putnbr_fd(i, fd);
// // 	close(fd);
// // 	return (0);
// // }

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}
