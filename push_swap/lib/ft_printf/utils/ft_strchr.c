/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:43 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/04 19:17:06 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

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
