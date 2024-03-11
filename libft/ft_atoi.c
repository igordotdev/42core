/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:28:46 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:57:01 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;

	minus = 1;
	i = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	while ((*nptr == '+' || *nptr == '-'))
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
		i++;
	}
	if (i >= 2)
		return (0);
	i = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		i *= 10;
		i += *nptr - '0';
		nptr++;
	}
	return (i * minus);
}
