/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:43 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:00:23 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	chr;

	chr = c;
	ptr = (char *)s;
	while (*ptr != chr && *ptr)
		ptr++;
	if (*ptr == chr)
		return (ptr);
	return (NULL);
}
