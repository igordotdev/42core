/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:40:09 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:27:28 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

static char	*assign_base(int help,
	char *result, unsigned long long n, char *base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base, 0);
	i = 0;
	while (i++ < help)
	{
		result[help - i] = base[n % base_len];
		n /= base_len;
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

char	*ft_itoa_base(unsigned long long n, char *base)
{
	unsigned long long	help;
	char				*result;
	unsigned long long	i;
	int					base_len;

	base_len = ft_strlen(base, 0);
	if (n == 0)
		return (itoa_zero());
	i = 0;
	help = n;
	while (help)
	{
		help /= base_len;
		i++;
	}
	result = (char *)malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	assign_base(i, result, n, base);
	return (result);
}
