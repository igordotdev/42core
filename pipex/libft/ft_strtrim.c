/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:47:50 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:01:11 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != c && set[i])
		i++;
	if (set[i] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;
	int		i;

	i = 0;
	first = 0;
	while ((is_in_set(s1[i], set)))
	{
		first++;
		i++;
	}
	i = (int)ft_strlen(s1) - 1;
	last = ft_strlen(s1);
	while ((is_in_set(s1[i], set)))
	{
		last--;
		i--;
	}
	str = ft_substr(s1, (unsigned int)first, last - first);
	return (str);
}
