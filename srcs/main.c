/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:57:09 by riyano            #+#    #+#             */
/*   Updated: 2025/01/28 17:33:07 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "../includes/push_swap.h"
#include "../libft/libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		error_and_exit();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_and_exit();
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -(result) < INT_MIN))
			error_and_exit();
	}
	return (result * sign);
}

int	count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			error_and_exit();
		j = 0;
		while (split[j++])
			count++;
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
	}
	return (count);
}

void	parse_args(int *arr, int argc, char **argv)
{
	int		i;
	int		j;
	int		idx;
	long	val;
	char	**split;

	idx = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			error_and_exit();
		j = 0;
		while (split[j])
		{
			val = ft_atol(split[j++]);
			arr[idx++] = (int)val;
		}
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		*arr;
	int		*sorted;
	int		total;

	if (argc < 2)
		return (0);
	total = count_tokens(argc, argv);
	if (total == 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * total);
	if (!arr)
		error_and_exit();
	parse_args(arr, argc, argv);
	sorted = malloc(sizeof(int) * total);
	normalize_numbers(arr, sorted, total);
	data = init_data(arr, total);
	sort_main(data);
	free(arr);
	free(sorted);
	free_data(data);
	return (0);
}
