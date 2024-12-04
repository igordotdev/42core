/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:39:38 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/09 07:56:40 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sub_header.h"

char	*ft_handle_uint(unsigned int num, t_flags *flags)
{
	char	*str;
	char	*anum;
	int		len;

	check_correct_flags(flags);
	anum = fft_itoa(num);
	if (anum == NULL)
		return (NULL);
	len = (int)fft_strlen(anum, 0);
	if (flags->precision > len)
		len = flags->precision;
	if (flags->width > len)
		str = (char *)fft_calloc((size_t)(flags->width + 1), sizeof(char));
	else
		str = (char *)fft_calloc((size_t)(len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (flags->minus)
		sub_handle_uint(flags, str, anum);
	else
		sub_handle_uint2(flags, str, anum, len);
	free(anum);
	return (str);
}

static int	sub_handle_hex_len(t_flags *flags, unsigned int num, int len)
{
	if (flags->precision > len)
		len = flags->precision;
	if (flags->hash && num != 0)
		len += 2;
	return (len);
}

char	*ft_handle_hex(unsigned int num, t_flags *flags, int case_type)
{
	char	*str;
	char	*anum;
	int		len;

	check_correct_flags(flags);
	if (case_type == 0)
		anum = fft_itoa_base(num, HEX);
	else
		anum = fft_itoa_base(num, HEX_UP);
	flags->case_type = case_type;
	if (anum == NULL)
		return (NULL);
	len = (int)fft_strlen(anum, 0);
	len = sub_handle_hex_len(flags, num, len);
	str = NULL;
	str = sub_handle_hex_str(flags, str, len);
	if (str == NULL)
		return (NULL);
	if (flags->minus)
		sub_handle_hex(flags, str, anum);
	else
		sub_handle_hex2(flags, str, anum, len);
	free(anum);
	return (str);
}

void	buffer_init(t_buffer *buffer)
{
	buffer->error = 0;
	buffer->index = 0;
	buffer->size = BUFFER_SIZE;
	buffer->content = fft_calloc(BUFFER_SIZE, sizeof(char));
}
