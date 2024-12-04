/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:51:02 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/17 09:05:08 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

char	*fft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*new;

	if (ptr == NULL)
		return (fft_calloc(size, 1));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = fft_calloc(size, 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
