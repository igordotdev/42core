/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:30:35 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 13:23:07 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_ints(t_data *data, int i, int j, char **argv)
{
	long long	num;

	num = ft_atol(&argv[i][j]);
	if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
		ft_exit(data, EIO);
	if (num > 2147483647 || num < -2147483647 - 1)
		ft_exit(data, EIO);
}

void	assign_arr(t_data *data, t_stack *stack, char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isprint(argv[i][j]) && !ft_isdigit(argv[i][j]) \
					&& argv[i][j] != '-')
				ft_exit(data, EIO);
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
			{
				check_ints(data, i, j, argv);
				stack->arr[stack->size++] = ft_atoi(&argv[i][j]);
				while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
					j++;
			}
			else
				j++;
		}
		i++;
	}
}

void	check_duplicates(t_data *data, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] == stack->arr[j])
				ft_exit(data, EIO);
			j++;
		}
		i++;
	}
}
