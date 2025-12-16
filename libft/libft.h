/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:55:11 by bfitte            #+#    #+#             */
/*   Updated: 2025/12/16 10:54:41 by bfitte/gmac      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Mem functions */
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

/* String functions */
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, size_t c);
unsigned long	ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);

/* Char functions */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

void			ft_bzero(void *s, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);

int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nmemb, size_t size);
char			**ft_split(char const *s, char c);

/* Fd functions */
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* Linked list functions */
t_stack			*ft_lstnew(int value);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
int				ft_lstsize(t_stack *lst);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			ft_lstdelone(t_stack *lst, void (*del)(int));
void			ft_lstclear(t_stack **lst, void (*del)(int));
void			ft_lstiter(t_stack *lst, void (*f)(int));
t_stack			*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));

/* ft_printf functions */
int				ft_printf(const char *format, ...);

size_t			ft_nbrlen(long n, size_t lbase);
size_t			ft_unbrlen(unsigned long n, size_t lbase);
char			*ft_itoabase(unsigned long n, const char *base);
void			ft_putnbrbase_fd(long n, int fd, const char *base);
void			ft_uputnbrbase_fd(unsigned long n, int fd, const char *base);

void			handle_int(va_list args, int *count);
void			handle_unsint(va_list args, int *count);
void			handle_hex(va_list args, int *count, char *base);
void			handle_ptr(va_list args, int *count, const char *base);

void			handle_char(va_list args, int *count);
void			handle_str(va_list args, int *count);
void			handle_perc(int *count);
void			handle_noargs(int *count, char c);

#endif
