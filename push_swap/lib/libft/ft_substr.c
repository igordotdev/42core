/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:18:40 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:01:18 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len + (size_t)start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = (char)s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
