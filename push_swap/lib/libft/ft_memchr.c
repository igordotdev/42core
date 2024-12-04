/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:27:57 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:20 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sptr;
	char	chr;

	sptr = (char *)s;
	chr = c;
	while (n-- != 0)
	{
		if (*sptr == chr)
			return (sptr);
		sptr++;
	}
	return (NULL);
}
