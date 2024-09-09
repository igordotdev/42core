/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:45:20 by idomagal          #+#    #+#             */
/*   Updated: 2024/07/19 05:45:20 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		pipe[2];
	int		pid1;
	int		pid2;
	int		status1;
	int		status2;
}	t_pipex;

#endif
