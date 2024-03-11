/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomagal <idomagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:03:29 by idomagal          #+#    #+#             */
/*   Updated: 2024/03/05 16:00:20 by idomagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_previous(char **s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	chrcount(const char *s, char c)
{
	int	i;
	int	count;
	int	trigger;

	count = 0;
	trigger = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger)
		{
			trigger = 0;
			count++;
		}
		else if (s[i] == c)
			trigger = 1;
		i++;
	}
	return (count);
}

static int	one_increment(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		number[3];

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((chrcount(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	number[0] = 0;
	number[2] = 0;
	while (number[0] < (int)ft_strlen(s))
	{
		number[1] = one_increment(s, c, number[0]);
		if (number[1] > 0)
		{
			result[number[2]] = ft_substr(s, number[0], (size_t)number[1]);
			if (result[number[2]] == NULL)
				return (free_previous(result, number[2]));
			number[2]++;
		}
		number[0] += number[1] + 1;
	}
	result[number[2]] = NULL;
	return (result);
}
