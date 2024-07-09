/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:12:01 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/27 19:20:26 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory_block;
	size_t	i;

	if (nmemb >= 4294967295 || size >= 4294967295)
	{
		if (size != 0 && nmemb != 0)
			return (NULL);
	}
	memory_block = malloc(nmemb * size);
	if (memory_block == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(memory_block + i) = 0;
		i++;
	}
	return (memory_block);
}

void	gnl_helper1(t_vars *vars, t_list *head, int fd)
{
	if (vars->cont->cont == NULL)
	{
		vars->buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (vars->buffer == NULL)
		{
			del_that_node(head, vars->cont);
			free(vars);
			vars->cont = NULL;
			return ;
		}
		vars->bytes = read(fd, vars->buffer, BUFFER_SIZE);
		vars->cont->cont = (char *)ft_calloc(1, 1);
		if (BUFFER_SIZE <= 0 || fd < 0 || vars->bytes < 0
			|| vars->cont->cont == NULL || vars->buffer[0] == '\0')
		{
			del_that_node(head, vars->cont);
			free(vars->buffer);
			free(vars);
			vars->cont = NULL;
			return ;
		}
		vars->cont->cont
			= ft_strjoin(vars->cont->cont, vars->buffer);
	}
	vars->outcome = 0;
}

int	ft_strlen(const char *s, int i)
{
	int	a;

	a = 0;
	if (i == 0)
	{
		while (*s)
		{
			a++;
			s++;
		}
	}
	else
	{
		if (s == NULL)
			return (-1);
		while (s[a] != '\0')
		{
			if (s[a] == '\n')
				return (a);
			a++;
		}
	}
	return (a);
}

char	*ft_split(char **s, int nl_position, int *delete_node)
{
	char	*result;
	char	*temp;

	if (s == NULL)
		return (NULL);
	result = ft_substr(*s, 0, nl_position + 1);
	temp = ft_substr(*s, nl_position + 1, ft_strlen(*s, 0) - nl_position);
	if ((int)(ft_strlen(*s, 0) - nl_position - 1) <= 0)
		*delete_node = 1;
	free(*s);
	*s = temp;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int		i;

	if (s == NULL || len <= 0)
		return (NULL);
	if (len > ft_strlen(s, 0))
		len = ft_strlen(s, 0);
	if (start >= (unsigned int)ft_strlen(s, 0))
		return (NULL);
	if (len + (int)start >= ft_strlen(s, 0))
		len = ft_strlen(s, 0) - start;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = (char)s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
