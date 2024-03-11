/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:31:28 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:23 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	while (n)
	{
		if (*s1ptr != *s2ptr)
			return (*s1ptr - *s2ptr);
		s1ptr++;
		s2ptr++;
		n--;
	}
	return (0);
}
