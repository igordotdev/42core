/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 07:53:12 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:36:32 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

size_t	fft_strlen(const char *s, int ignore_null)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	if (ignore_null == 1)
	{
		a++;
		while (s[a] != '\0')
			a++;
	}
	return (a);
}
