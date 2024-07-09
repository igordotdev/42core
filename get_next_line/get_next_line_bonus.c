/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:28:16 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/27 19:17:24 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = ft_strlen(s1, 0);
	len2 = ft_strlen(s2, 0);
	str = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (i++ < len1)
		str[i] = (char)s1[i];
	i = -1;
	while (i++ < len2)
		str[len1 + i] = (char)s2[i];
	free(s1);
	free(s2);
	return (str);
}

t_list	*get_node(t_list **head, int fd, t_vars *vars)
{
	t_list	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_list *)ft_calloc(1, sizeof(t_list));
	if (current == NULL)
	{
		free(vars);
		return (NULL);
	}
	current->fd = fd;
	current->cont = NULL;
	current->next = *head;
	*head = current;
	return (current);
}

void	del_that_node(t_list *head, t_list *node)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	current = head;
	prev = NULL;
	while (current)
	{
		next = current->next;
		if (current == node)
		{
			if (prev != NULL)
				prev->next = next;
			else
				head = next;
			free(current->cont);
			free(current);
			return ;
		}
		prev = current;
		current = next;
	}
}

static void	gnl_helper2(t_vars *vars, t_list *head, int fd)
{
	while ((vars->nl_pos == (int)ft_strlen(vars->cont->cont, 0)
			|| vars->nl_pos == -1) && vars->bytes > 0)
	{
		vars->buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (vars->buffer == NULL)
		{
			del_that_node(head, vars->cont);
			free(vars);
			return ;
		}
		vars->bytes = read(fd, vars->buffer, BUFFER_SIZE);
		if (vars->bytes <= 0
			&& ft_strlen(vars->cont->cont, 0) == 0)
		{
			del_that_node(head, vars->cont);
			free(vars->buffer);
			free(vars);
			return ;
		}
		if (ft_strlen(vars->buffer, 0) < BUFFER_SIZE)
			vars->delete_node[0] = 1;
		vars->cont->cont = ft_strjoin(vars->cont->cont, vars->buffer);
		vars->nl_pos = ft_strlen(vars->cont->cont, 1);
	}
	vars->outcome = 0;
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_vars			*vars;
	char			*line;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->bytes = 1;
	vars->outcome = 1;
	vars->cont = get_node(&head, fd, vars);
	if (vars->cont == NULL)
		return (NULL);
	gnl_helper1(vars, head, fd);
	if (vars->outcome)
		return (NULL);
	vars->nl_pos = ft_strlen(vars->cont->cont, 1);
	gnl_helper2(vars, head, fd);
	if (vars->outcome)
		return (NULL);
	line = ft_split(&vars->cont->cont,
			vars->nl_pos, &vars->delete_node[1]);
	if (vars->delete_node[1] && vars->delete_node[0])
		del_that_node(head, vars->cont);
	free(vars);
	return (line);
}
