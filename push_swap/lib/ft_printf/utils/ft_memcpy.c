/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:30:34 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/27 16:36:43 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (a < n)
	{
		*(char *)(dest + a) = *(char *)(src + a);
		a++;
	}
	return (dest);
}
