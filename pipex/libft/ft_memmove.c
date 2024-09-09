/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:44:15 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:59 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		dest_ptr += n - 1;
		src_ptr += n - 1;
		while (n--)
			*dest_ptr-- = *src_ptr--;
	}
	else
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}
