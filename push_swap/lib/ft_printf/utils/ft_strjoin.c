/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:28:14 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/04 19:17:14 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

char	*fft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char *)fft_calloc((len1 + len2 + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (i++ < len1)
		str[i] = (char)s1[i];
	i = -1;
	while (i++ < len2)
		str[len1 + i] = (char)s2[i];
	return (str);
}
