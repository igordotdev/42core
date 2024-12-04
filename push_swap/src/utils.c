/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:52:41 by idomagal          #+#    #+#             */
/*   Updated: 2024/09/10 08:22:22 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	mean(int *arr, int size)
{
	double	sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += (double)arr[i];
		i++;
	}
	return (sum / (double)size);
}

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*new;

	if (ptr == NULL)
		return (ft_calloc(size, 1));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = ft_calloc(size, 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}

void	ft_exit(t_data *data, int code)
{
	ft_putstr_fd("Error\n", 2);
	if (data->sorted)
		free(data->sorted);
	free(data->actions);
	free(data->stack_a->arr);
	free(data->stack_b->arr);
	free(data->stack_a);
	free(data->stack_b);
	exit(code);
}

int	max_value_index(int *arr, int size)
{
	int	max;
	int	i;
	int	index;

	index = 0;
	max = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

long long	ft_atol(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
