/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:07:58 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:00:39 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destsize;
	size_t	srcsize;

	i = 0;
	destsize = 0;
	srcsize = 0;
	while (dst[destsize] && destsize < size)
	{
		destsize++;
	}
	while (src[srcsize])
	{
		srcsize++;
	}
	if (destsize < size)
	{
		while (src[i] && (destsize + i) < size -1)
		{
			dst[destsize + i] = src[i];
			i++;
		}
		dst[destsize + i] = '\0';
	}
	return (destsize + srcsize);
}
