/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:20:18 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:01:02 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	chr;
	int		i;

	ptr = (char *)s;
	chr = c;
	i = 0;
	while (*(s + i))
		i++;
	ptr += i;
	while (*ptr != chr && ptr != s)
		ptr--;
	if (*ptr == chr)
		return (ptr);
	else
		return (NULL);
}
