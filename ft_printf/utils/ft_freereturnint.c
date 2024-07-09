/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freereturnint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:42:39 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/04 19:16:47 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_header.h"

int	ft_freereturnint(int val, void *ptr)
{
	free(ptr);
	if (val == -1)
		return (-1);
	return (0);
}
