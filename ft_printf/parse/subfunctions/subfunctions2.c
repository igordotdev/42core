/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:02:20 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:33:51 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sub_header.h"

void	sub_handle_nint2(t_flags *flags, char *str, char *anum, int len)
{
	int	i;

	i = 0;
	if (flags->zero && !flags->dot)
	{
		str[i++] = '-';
		while (i < flags->width - len)
			str[i++] = '0';
	}
	else
	{
		while (i < flags->width - len - 1)
			str[i++] = ' ';
		str[i++] = '-';
	}
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (flags->precision-- > (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
}

void	*sub_handle_int1(t_flags *flags, int len)
{
	char	*str;

	if (flags->width > len)
		str = (char *)ft_calloc((size_t)(flags->width + 1), sizeof(char));
	else
		str = (char *)ft_calloc((size_t)(len + 1), sizeof(char));
	return (str);
}

void	sub_handle_int2(t_flags *flags, char *str, char *anum)
{
	int	i;

	i = 0;
	if (flags->plus)
		str[i++] = '+';
	else if (flags->space)
		str[i++] = ' ';
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (i < flags->precision - (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
	i += (int)ft_strlen(anum, 0);
	while (i < flags->width)
		str[i++] = ' ';
}

int	ssub_handle_int3(t_flags *flags, char *str, int i, int len)
{
	if (flags->plus)
		str[i++] = '+';
	else if (flags->space)
		str[i++] = ' ';
	if (flags->space || flags->plus)
		while (i < flags->width - len + 1)
			str[i++] = '0';
	else
		while (i < flags->width - len)
			str[i++] = '0';
	return (i);
}

void	sub_handle_int3(t_flags *flags, char *str, char *anum, int len)
{
	int	i;

	i = 0;
	if (flags->zero && !flags->dot)
		i = ssub_handle_int3(flags, str, i, len);
	else
	{
		while (i < flags->width - len)
			str[i++] = ' ';
		if (flags->plus)
			str[i++] = '+';
		else if (flags->space)
			str[i++] = ' ';
	}
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (flags->precision-- > (int)ft_strlen(anum, 0))
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
}
