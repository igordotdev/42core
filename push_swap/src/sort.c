/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:22:13 by idomagal          #+#    #+#             */
/*   Updated: 2024/09/10 08:22:13 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_more(t_data *data)
{
	double	average;
	int		a_len;

	while (data->stack_a->size > 5)
	{
		average = mean(data->stack_a->arr, data->stack_a->size);
		if ((double)data->stack_a->arr[0] < average)
			push(data, data->stack_a, data->stack_b);
		else
			rotate(data->stack_a);
	}
	sort_5(data, data->stack_a);
	while (data->stack_b->size > 0)
		bff_moves(data);
	a_len = data->stack_a->size;
	if (max_value_index(data->stack_a->arr, a_len) < a_len / 2)
	{
		while (max_value_index(data->stack_a->arr, a_len) != a_len - 1)
			rotate(data->stack_a);
	}
	else
	{
		while (max_value_index(data->stack_a->arr, a_len) != a_len - 1)
			rev_rotate(data->stack_a);
	}
}

void	bff_moves(t_data *data)
{
	t_cost	*costs;
	int		i;
	int		j;
	int		min;
	int		iter;

	costs = (t_cost *)malloc(data->stack_b->size * sizeof(*costs));
	if (!costs)
		ft_exit(data, 1);
	i = 0;
	j = 0;
	min = 2147483647;
	data->costs = costs;
	calculate_costs(i, j, min, data);
	i = find_min_cost(costs, data->stack_b->size);
	iter = 0;
	rotate_b(data, i, iter);
	iter = 0;
	rotate_a(data, i, iter);
	free(costs);
	push(data, data->stack_b, data->stack_a);
}

void	calculate_costs(int i, int j, int min, t_data *data)
{
	while (i < data->stack_b->size)
	{
		j = 0;
		min = 2147483647;
		while (j < data->stack_a->size)
		{
			if (data->stack_a->arr[j] - data->stack_b->arr[i] >= 0 \
					&& data->stack_a->arr[j] - data->stack_b->arr[i] < min)
			{
				min = data->stack_a->arr[j] - data->stack_b->arr[i];
				data->costs[i].bud = j;
			}
			j++;
		}
		if (data->costs[i].bud < data->stack_a->size / 2)
			data->costs[i].cost = data->costs[i].bud;
		else
			data->costs[i].cost = data->stack_a->size - data->costs[i].bud;
		if (i < data->stack_b->size / 2)
			data->costs[i].cost += i;
		else
			data->costs[i].cost += data->stack_b->size - i;
		i++;
	}
}

void	rotate_b(t_data *data, int i, int iter)
{
	int	rots;

	if (i < data->stack_b->size / 2)
	{
		while (iter < i)
		{
			rotate(data->stack_b);
			iter++;
		}
	}
	else
	{
		rots = data->stack_b->size - i;
		while (iter < rots)
		{
			rev_rotate(data->stack_b);
			iter++;
		}
	}
}

void	rotate_a(t_data *data, int i, int iter)
{
	int	rots;

	if (data->costs[i].bud < data->stack_a->size / 2)
	{
		while (iter < data->costs[i].bud)
		{
			rotate(data->stack_a);
			iter++;
		}
	}
	else
	{
		rots = data->stack_a->size - data->costs[i].bud;
		while (iter < rots)
		{
			rev_rotate(data->stack_a);
			iter++;
		}
	}
}
