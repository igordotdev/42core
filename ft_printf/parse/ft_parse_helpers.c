/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:49:16 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:58:09 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_header.h"

int	ft_parse_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (format[i] && ft_strchr("# +-0", format[i]))
	{
		if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		i++;
	}
	return (i);
}

int	ft_parse_width(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (format[i] && ft_isdigit(format[i]))
	{
		flags->width = (flags->width * 10) + (format[i] - '0');
		i++;
	}
	return (i);
}

int	ft_parse_precision(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		flags->dot = 1;
		i++;
		while (format[i] && ft_isdigit(format[i]))
		{
			flags->precision = (flags->precision * 10) + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

char	*ft_parse_type(char format, t_flags *flags, va_list arg)
{
	if (format == 'c')
		return (ft_handle_char(va_arg(arg, int), flags));
	else if (format == 's')
		return (ft_handle_string(va_arg(arg, char *), flags));
	else if (format == 'p')
		return (ft_handle_pointer(va_arg(arg, void *), flags));
	else if (format == 'd' || format == 'i')
		return ((ft_handle_int(va_arg(arg, int), flags)));
	else if (format == 'u')
		return (ft_handle_uint(va_arg(arg, unsigned int), flags));
	else if (format == 'x')
		return (ft_handle_hex(va_arg(arg, unsigned int), flags, 0));
	else if (format == 'X')
		return (ft_handle_hex(va_arg(arg, unsigned int), flags, 1));
	else if (format == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}
