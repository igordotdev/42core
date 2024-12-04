/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:43:15 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:06 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*del_done(t_list *head, void (*del)(void *), void *content)
{
	del(content);
	ft_lstclear(&head, del);
	free(head);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodes[3];
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	nodes[0] = lst;
	content = f(nodes[0]->content);
	nodes[2] = ft_lstnew(content);
	if (nodes[2] == NULL)
	{
		del(content);
		return (NULL);
	}
	nodes[0] = nodes[0]->next;
	while (nodes[0])
	{
		content = f(nodes[0]->content);
		nodes[1] = ft_lstnew(content);
		if (nodes[1] == NULL)
			return (del_done(nodes[2], del, content));
		ft_lstadd_back(&nodes[2], nodes[1]);
		nodes[0] = nodes[0]->next;
	}
	return (nodes[2]);
}
