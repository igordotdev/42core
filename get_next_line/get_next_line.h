/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:08:31 by idomagal          #+#    #+#             */
/*   Updated: 2024/06/27 19:19:30 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*cont;
	int				fd;
	struct s_list	*next;
}				t_list;

typedef struct variables
{
	t_list				*cont;
	char				*buffer;
	int					nl_pos;
	int					bytes;
	int					delete_node[2];
	int					outcome;
}			t_vars;

char		*get_next_line(int fd);
int			ft_strlen(const char *s, int i);
char		*ft_substr(char const *s, unsigned int start, int len);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_realloc(void *ptr, size_t size, size_t old_size);
void		del_that_node(t_list *head, t_list *node);
char		*ft_split(char **s, int nl_position, int *delete_node);
void		gnl_helper1(t_vars *vars, t_list *head, int fd);
char		*ft_strjoin(char *s1, char *s2);

#endif