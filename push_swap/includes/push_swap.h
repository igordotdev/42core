/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:45:01 by idomagal          #+#    #+#             */
/*   Updated: 2024/08/07 07:45:02 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include <errno.h>

typedef struct s_cost
{
	int	cost;
	int	bud;
}	t_cost;

typedef struct s_stack
{
	int		ab;
	int		*arr;
	int		size;
}	t_stack;

typedef struct s_data
{
	t_cost	*costs;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*actions;
	int		*sorted;
}	t_data;

long long	ft_atol(const char *str);
// actions.c
void		swap(t_stack *stack);
void		push(t_data *data, t_stack *from, t_stack *to);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);

// input.c
void		assign_arr(t_data *data, t_stack *stack, char **argv, int argc);
void		check_duplicates(t_data *data, t_stack *stack);

// sort.c
void		sort_more(t_data *data);
void		bff_moves(t_data *data);
void		calculate_costs(int i, int j, int min, t_data *data);
void		rotate_b(t_data *data, int i, int iter);
void		rotate_a(t_data *data, int i, int iter);

// small_sorts.c
void		sort_3(t_stack *stack);
void		sort_5(t_data *data, t_stack *stack);
int			is_descending(t_stack *stack);

// utils.c
double		mean(int *arr, int size);
void		*ft_realloc(void *ptr, size_t size, size_t old_size);
void		ft_exit(t_data *data, int code);
int			max_value_index(int *arr, int size);

// sort_utils.c
int			is_sorted(t_stack *stack);
void		bubble_sort(int *arr, int size);
int			find_min_cost(t_cost *costs, int size);

#endif