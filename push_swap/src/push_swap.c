/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:44:49 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 13:36:20 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	data_init(t_data *data, int argc, char **argv)
{
	data->stack_a = ft_calloc(1, sizeof(t_stack));
	data->stack_b = ft_calloc(1, sizeof(t_stack));
	data->stack_a->arr = ft_calloc(argc, sizeof(int));
	data->stack_b->arr = ft_calloc(argc, sizeof(int));
	data->stack_a->ab = 0;
	data->stack_b->ab = 1;
	data->stack_a->size = 0;
	data->stack_b->size = 0;
	data->actions = ft_calloc(1, 1);
	data->sorted = NULL;
	assign_arr(data, data->stack_a, argv, argc);
	data->sorted = ft_calloc(data->stack_a->size, sizeof(int));
	ft_memcpy(data->sorted, data->stack_a->arr, \
		data->stack_a->size * sizeof(int));
	bubble_sort(data->sorted, data->stack_a->size);
}

static void	free_data(t_data *data)
{
	free(data->stack_a->arr);
	free(data->stack_b->arr);
	free(data->stack_a);
	free(data->stack_b);
	free(data->sorted);
	free(data->actions);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data_init(&data, argc, argv);
	check_duplicates(&data, data.stack_a);
	if (is_sorted(data.stack_a))
	{
		free_data(&data);
		return (0);
	}
	if (data.stack_a->size <= 5)
		sort_5(&data, data.stack_a);
	else
		sort_more(&data);
	free_data(&data);
	return (0);
}
