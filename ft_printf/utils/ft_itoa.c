/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:19:40 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/12 16:28:55 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

static char	*assign(int help, char *result, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < (unsigned int)help)
	{
		result[help - i] = (n % 10) + '0';
		n /= 10;
	}
	result[help] = '\0';
	return (result);
}

static char	*itoa_zero(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(unsigned int n)
{
	unsigned int		help;
	char				*result;
	unsigned int		i;

	if (n == 0)
		return (itoa_zero());
	i = 0;
	help = n;
	while (help)
	{
		help /= 10;
		i++;
	}
	result = (char *)malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	assign(i, result, (unsigned int) n);
	return (result);
}
