/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:55:22 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 13:32:24 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 2)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_min_cost(t_cost *costs, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = 2147483647;
	min_index = 0;
	while (i < size)
	{
		if (costs[i].cost < min)
		{
			min = costs[i].cost;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
