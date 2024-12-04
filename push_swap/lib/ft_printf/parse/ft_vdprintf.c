/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:40:39 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:59:12 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_header.h"

char	*ft_parse(const char **format, va_list arg, t_flags *flags)
{
	char	*str;

	*flags = (t_flags){0, 0,
		0, 0, 0, 0, 0, 0, 0, 0};
	(*format) += ft_parse_flags(*format, flags);
	(*format) += ft_parse_width(*format, flags);
	(*format) += ft_parse_precision(*format, flags);
	str = ft_parse_type(**format, flags, arg);
	if (str == NULL)
		return (NULL);
	(*format)++;
	return (str);
}

static int	sub_handle_fs(t_buffer *buffer, char *str, int len)
{
	char	*temp;

	if (buffer->index + len > buffer->size)
	{
		temp = fft_realloc(buffer->content,
				buffer->index + len + 1, buffer->size);
		if (temp == NULL)
		{
			free(buffer->content);
			return (ft_freereturnint(-1, str));
		}
		buffer->content = temp;
		buffer->size += len;
	}
	ft_memcpy(buffer->content + buffer->index, str, len);
	buffer->index += len;
	free(str);
	return (0);
}

int	handle_format_specifier(const char **format, va_list arg,
	t_buffer *buffer, t_flags *flags)
{
	char	*str;
	int		len;

	str = ft_parse(format, arg, flags);
	if (str)
	{
		len = (int)fft_strlen(str, flags->is_null);
		if (flags->is_null)
			flags->is_null = 0;
		return (sub_handle_fs(buffer, str, len));
	}
	else
		return (-1);
	return (0);
}

int	handle_regular_character(const char **format, t_buffer *buffer)
{
	char	*temp;

	if (buffer->index + 1 > buffer->size)
	{
		temp = fft_realloc(buffer->content, buffer->index + 2, buffer->size);
		if (temp == NULL)
			return (ft_freereturnint(-1, buffer->content));
		buffer->content = temp;
		buffer->size *= 2;
	}
	buffer->content[buffer->index] = **format;
	(buffer->index)++;
	(*format)++;
	return (0);
}

int	ft_vdprintf(int fd, const char *format, va_list arg)
{
	t_buffer	buffer;
	t_flags		flags;

	ft_bzero(&flags, sizeof(flags));
	buffer_init(&buffer);
	if (buffer.content == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			buffer.error = handle_format_specifier(&format, arg,
					&buffer, &flags);
		}
		else
			buffer.error = handle_regular_character(&format, &buffer);
		if (buffer.error == -1)
			return (ft_freereturnint(-1, buffer.content));
	}
	buffer.content[buffer.index] = '\0';
	write(fd, buffer.content, buffer.index);
	free(buffer.content);
	return (buffer.index);
}
