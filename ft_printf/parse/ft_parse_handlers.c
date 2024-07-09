/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:20:38 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:53:41 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_header.h"
#include <stdio.h>

char	*ft_handle_char(char chr, t_flags *flags)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc((size_t)(flags->width + 2), sizeof(char));
	if (chr == 0)
		flags->is_null = 1;
	if (str == NULL)
		return (NULL);
	i = 0;
	sub_handle_char(flags, str, chr, i);
	return (str);
}

char	*ft_handle_string(char *str, t_flags *flags)
{
	char	*new_str;
	int		len;

	if (str == NULL && flags->dot && flags->precision < 6)
		str = "";
	else if (str == NULL)
		str = "(null)";
	len = (int)ft_strlen(str, 0);
	if (flags->precision >= 0 && flags->precision < len && flags->dot)
		len = flags->precision;
	new_str = (char *)ft_calloc((size_t)(flags->width + 2 + len), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	sub_handle_string(flags, str, new_str, len);
	return (new_str);
}

char	*ft_handle_pointer(void *address, t_flags *flags)
{
	char	*str;
	char	*temp;

	if (address == NULL)
		return (ft_strdup("(nil)"));
	else
	{
		temp = ft_itoa_base((intptr_t)address, HEX);
		if (temp == NULL)
			return (NULL);
		str = ft_strjoin("0x", temp);
		free(temp);
		if (str == NULL)
			return (NULL);
		str = sub_handle_pointer(flags, str, temp);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	*ft_handle_nint(unsigned int num, t_flags *flags)
{
	char	*str;
	char	*anum;
	int		len;

	check_correct_flags(flags);
	num = -num;
	anum = ft_itoa(num);
	if (anum == NULL)
		return (NULL);
	len = (int)ft_strlen(anum, 0);
	if (flags->precision > len)
		len = flags->precision;
	if (flags->width > len)
		str = (char *)ft_calloc((size_t)(flags->width + 1), sizeof(char));
	else
		str = (char *)ft_calloc((size_t)(len + 2), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (flags->minus)
		sub_handle_nint1(flags, str, anum);
	else
		sub_handle_nint2(flags, str, anum, len);
	free(anum);
	return (str);
}

char	*ft_handle_int(int num, t_flags *flags)
{
	char	*str;
	char	*anum;
	int		len;

	check_correct_flags(flags);
	if (num < 0)
		return (ft_handle_nint((unsigned int)num, flags));
	anum = ft_itoa(num);
	if (anum == NULL)
		return (NULL);
	len = (int)ft_strlen(anum, 0);
	if (flags->precision > len)
		len = flags->precision;
	len += flags->plus + flags->space;
	str = sub_handle_int1(flags, len);
	if (str == NULL)
		return (NULL);
	if (flags->minus)
		sub_handle_int2(flags, str, anum);
	else
		sub_handle_int3(flags, str, anum, len);
	free(anum);
	return (str);
}
