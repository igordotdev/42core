/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:37:55 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:21:41 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HEADER_H
# define PARSE_HEADER_H

# include "sub_header.h"
# include "utils_header.h"
# include <stdarg.h>
# define TYPE "cspdiuxX%"

int		ft_parse_flags(const char *format, t_flags *flags);
int		ft_parse_width(const char *format, t_flags *flags);
int		ft_parse_precision(const char *format, t_flags *flags);
int		ft_parse_length(const char *format, t_flags *flags);
char	*ft_parse_type(char format, t_flags *flags, va_list arg);
char	*ft_parse(const char **format, va_list arg, t_flags *flags);
int		handle_format_specifier(const char **format,
			va_list arg, t_buffer *buffer, t_flags *flags);
int		handle_regular_character(const char **format, t_buffer *buffer);
int		ft_vdprintf(int fd, const char *format, va_list arg);
char	*ft_handle_char(char chr, t_flags *flags);
char	*ft_handle_string(char *str, t_flags *flags);
char	*ft_handle_pointer(void *address, t_flags *flags);
char	*ft_handle_int(int num, t_flags *flags);
char	*ft_handle_nint(unsigned int num, t_flags *flags);
char	*ft_handle_uint(unsigned int num, t_flags *flags);
char	*ft_handle_hex(unsigned int num, t_flags *flags, int case_type);

#endif