/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:55:24 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 12:55:33 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1]
		< stack->arr[2] && stack->arr[0] < stack->arr[2])
		swap(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		swap(stack);
		rev_rotate(stack);
	}
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1]
		< stack->arr[2] && stack->arr[0] > stack->arr[2])
		rotate(stack);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1]
		> stack->arr[2] && stack->arr[0] > stack->arr[2])
		rev_rotate(stack);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1]
		> stack->arr[2] && stack->arr[0] < stack->arr[2])
	{
		rev_rotate(stack);
		swap(stack);
	}
}

void	sort_5(t_data *data, t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	while (stack->size > 3)
	{
		if (stack->arr[0] == data->sorted[0])
			push(data, stack, data->stack_b);
		else
		{
			if (is_descending(stack) == 1)
				rev_rotate(stack);
			else
				rotate(stack);
		}
		data->sorted = ft_realloc(data->sorted, (stack->size - 1) * sizeof(int),
				(stack->size - 1) * sizeof(int));
		ft_memcpy(data->sorted, stack->arr, (stack->size - 1) * sizeof(int));
		bubble_sort(data->sorted, stack->size);
	}
	if (data->stack_b->arr[0] < data->stack_b->arr[1])
		swap(data->stack_b);
	sort_3(stack);
	push(data, data->stack_b, stack);
	push(data, data->stack_b, stack);
	if (stack->arr[0] > stack->arr[1])
		swap(stack);
}

int	is_descending(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
