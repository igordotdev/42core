/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:33:15 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:00:57 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlelen;
	size_t	i;
	size_t	n;

	n = 0;
	littlelen = 0;
	if (!*little)
		return ((char *)big);
	while (little[littlelen])
		littlelen++;
	while (*(char *)big && n < len)
	{
		i = 0;
		while (big[i] == little[i] && n < len)
		{
			i++;
			n++;
			if (i == littlelen)
				return ((char *)big);
		}
		n -= i;
		n++;
		big++;
	}
	return (0);
}
