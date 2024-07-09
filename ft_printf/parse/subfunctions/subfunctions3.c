/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:05:13 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:28:53 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sub_header.h"

void	sub_handle_uint(t_flags *flags, char *str, char *anum)
{
	intptr_t	i;

	i = 0;
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (i < flags->precision - (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
	i += (int)ft_strlen(anum, 0);
	while (i < flags->width)
		str[i++] = ' ';
}

void	sub_handle_uint2(t_flags *flags, char *str, char *anum, int len)
{
	int	i;

	i = 0;
	if (flags->zero && !flags->dot)
		while (i < flags->width - len)
			str[i++] = '0';
	else
		while (i < flags->width - len)
			str[i++] = ' ';
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (flags->precision-- > (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
}

void	sub_handle_hex(t_flags *flags, char *str, char *anum)
{
	int	i;

	i = 0;
	if (flags->hash && anum[0] != '0')
	{
		if (flags->case_type == 0)
			ft_memcpy(str, "0x", 2);
		else
			ft_memcpy(str, "0X", 2);
		i += 2;
	}
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (i < flags->precision
			- (int)ft_strlen(anum, 0) + 2 * flags->hash)
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
	i += (int)ft_strlen(anum, 0);
	while (i < flags->width)
		str[i++] = ' ';
}

void	sub_handle_hex2(t_flags *flags, char *str, char *anum, int len)
{
	int	i;

	i = 0;
	if (flags->zero && !flags->dot)
		while (i < flags->width - len)
			str[i++] = '0';
	else
		while (i < flags->width - len)
			str[i++] = ' ';
	if (flags->hash && anum[0] != '0')
	{
		if (flags->case_type == 0)
			ft_memcpy(str + i, "0x", 2);
		else
			ft_memcpy(str + i, "0X", 2);
		i += 2;
	}
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (flags->precision-- > (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
}

void	*sub_handle_hex_str(t_flags *flags, char *str, int len)
{
	if (flags->width > len)
		str = (char *)ft_calloc((size_t)(flags->width + 1), sizeof(char));
	else
		str = (char *)ft_calloc((size_t)(len + 1), sizeof(char));
	return (str);
}
