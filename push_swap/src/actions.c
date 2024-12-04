/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:16:19 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 13:34:51 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	if (stack->ab == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

static void	push_helper(t_stack *from, t_stack *to)
{
	int	i;

	i = 0;
	while (i < from->size - 1)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	from->size--;
	to->size++;
}

void	push(t_data *data, t_stack *from, t_stack *to)
{
	int	i;

	if (from->size == 0)
		return ;
	to->arr = ft_realloc(to->arr, (to->size + 1) \
		* sizeof(int), to->size * sizeof(int));
	if (to->arr == NULL)
		ft_exit(data, ENOMEM);
	i = to->size;
	while (i > 0)
	{
		to->arr[i] = to->arr[i - 1];
		i--;
	}
	to->arr[0] = from->arr[0];
	push_helper(from, to);
	if (to->ab == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
	if (stack->ab == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rev_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = tmp;
	if (stack->ab == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
