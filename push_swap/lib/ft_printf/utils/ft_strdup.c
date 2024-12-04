/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:28:24 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/04 19:17:09 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = 0;
	while (*(char *)(s + len))
		len++;
	dup = (char *)malloc((len * sizeof(char)) + 1);
	if (dup == NULL)
		return (NULL);
	while (*s)
		*dup++ = *s++;
	*dup = 0;
	return (dup - len);
}
