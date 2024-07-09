/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:33:13 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:59:47 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sub_header.h"
#include <stdio.h>

void	check_correct_flags(t_flags *flags)
{
	if (flags->plus && flags->space)
		flags->space = 0;
	if (flags->minus)
		flags->zero = 0;
}

void	sub_handle_char(t_flags *flags, char *str, char chr, int i)
{
	if (flags->minus)
	{
		str[0] = chr;
		i++;
		while (i < flags->width)
		{
			str[i] = ' ';
			i++;
		}
	}
	else
	{
		while (i < flags->width - 1)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = chr;
	}
}

void	sub_handle_string(t_flags *flags, char *str, char *new_str, int len)
{
	int	i;

	i = 0;
	if (flags->minus)
	{
		ft_memcpy(new_str, str, len);
		i = len;
		while (i < flags->width)
		{
			new_str[i] = ' ';
			i++;
		}
	}
	else
	{
		while (i < flags->width - len)
		{
			new_str[i] = ' ';
			i++;
		}
		ft_memcpy(new_str + i, str, len);
	}
}

void	*sub_handle_pointer(t_flags *flags, char *str, char *temp)
{
	if (flags->width > (int)ft_strlen(str, 0))
	{
		if (flags->minus)
		{
			temp = (char *)ft_calloc((size_t)flags->width
					- ft_strlen(str, 0) + 1, 1);
			if (temp == NULL)
				return (NULL);
			temp = ft_memset(temp, ' ',
					(size_t)flags->width - ft_strlen(str, 0));
			str = ft_strjoin(str, temp);
		}
		else
		{
			temp = (char *)ft_calloc((size_t)flags->width
					- ft_strlen(str, 0), 1);
			if (temp == NULL)
				return (NULL);
			temp = ft_memset(temp, ' ',
					(size_t)flags->width - ft_strlen(str, 0));
			str = ft_strjoin(temp, str);
		}
	}
	return (str);
}

void	sub_handle_nint1(t_flags *flags, char *str, char *anum)
{
	int	i;

	i = 0;
	str[i++] = '-';
	if (flags->precision > (int)ft_strlen(anum, 0))
		while (i < flags->precision - (int)ft_strlen(anum, 0) + 1)
			str[i++] = '0';
	ft_memcpy(str + i, anum, ft_strlen(anum, 0));
	i += (int)ft_strlen(anum, 0);
	while (i < flags->width)
		str[i++] = ' ';
}
