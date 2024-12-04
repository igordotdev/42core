/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:28:14 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/09 08:08:36 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

void	*fft_calloc(size_t nmemb, size_t size)
{
	void	*memory_block;

	if (nmemb >= 4294967295 || size >= 4294967295)
	{
		if (size != 0 && nmemb != 0)
			return (NULL);
	}
	memory_block = malloc(nmemb * size);
	if (memory_block == NULL)
		return (NULL);
	ft_bzero(memory_block, nmemb * size);
	return (memory_block);
}
