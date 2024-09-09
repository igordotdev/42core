/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:28:14 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:57:54 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory_block;
	size_t	i;

	if (nmemb >= 4294967295 || size >= 4294967295)
	{
		if (size != 0 && nmemb != 0)
			return (NULL);
	}
	memory_block = malloc(nmemb * size);
	if (memory_block == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(memory_block + i) = 0;
		i++;
	}
	return (memory_block);
}
