/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:42:06 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:30:44 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		done;
	va_list	arg;

	va_start(arg, format);
	done = ft_vdprintf(1, format, arg);
	va_end(arg);
	return (done);
}
