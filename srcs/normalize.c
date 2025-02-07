/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:46:52 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 19:47:28 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_duplicates(int *arr, int *sorted, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (sorted[i] == sorted[i + 1])
		{
			write(2, "Error\n", 6);
			free(arr);
			free(sorted);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static int	find_index(int *sorted, int n, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sorted[mid] == value)
			return (mid);
		else if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	normalize_numbers(int *arr, int *sorted, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort_arr(sorted, 0, n - 1);
	check_duplicates(arr, sorted, n);
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(sorted, n, arr[i]);
		i++;
	}
}
