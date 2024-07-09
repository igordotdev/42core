/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:34:05 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:32:34 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HEADER_H
# define UTILS_HEADER_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	*content;
	int		size;
	int		index;
	int		error;
}	t_buffer;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_freereturnint(int val, void *ptr);
int		ft_isdigit(int c);
char	*ft_itoa_base(unsigned long long n, char *base);
char	*ft_itoa(unsigned int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_realloc(void *ptr, size_t size, size_t old_size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s, int ignore_null);

#endif