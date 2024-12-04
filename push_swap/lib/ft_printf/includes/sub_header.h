/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:32:12 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/08 22:11:16 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_HEADER_H
# define SUB_HEADER_H

# include "utils_header.h"
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define BUFFER_SIZE 1024

typedef struct s_flags
{
	int		hash;
	int		space;
	int		minus;
	int		plus;
	int		zero;
	int		precision;
	int		dot;
	int		width;
	int		case_type;
	int		is_null;

}	t_flags;

void	check_correct_flags(t_flags *flags);
void	sub_handle_char(t_flags *flags, char *str, char chr, int i);
void	sub_handle_string(t_flags *flags, char *str, char *new_str, int len);
void	*sub_handle_pointer(t_flags *flags, char *str, char *temp);
void	sub_handle_nint1(t_flags *flags, char *str, char *anum);
void	sub_handle_nint2(t_flags *flags, char *str, char *anum, int len);
void	*sub_handle_int1(t_flags *flags, int len);
void	sub_handle_int2(t_flags *flags, char *str, char *anum);
int		ssub_handle_int3(t_flags *flags, char *str, int i, int len);
void	sub_handle_int3(t_flags *flags, char *str, char *anum, int len);
void	sub_handle_uint(t_flags *flags, char *str, char *anum);
void	sub_handle_uint2(t_flags *flags, char *str, char *anum, int len);
void	sub_handle_hex(t_flags *flags, char *str, char *anum);
void	sub_handle_hex2(t_flags *flags, char *str, char *anum, int len);
void	*sub_handle_hex_str(t_flags *flags, char *str, int len);
void	buffer_init(t_buffer *buffer);
char	*ft_handle_hex(unsigned int num, t_flags *flags, int case_type);
char	*ft_handle_uint(unsigned int num, t_flags *flags);

#endif