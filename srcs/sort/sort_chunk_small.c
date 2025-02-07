/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:44:38 by riyano            #+#    #+#             */
/*   Updated: 2025/02/05 13:04:45 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three_top_a(t_data *data, t_chunk *to_sort, int max);

void	sort_chunk_two(t_data *data, t_chunk *to_sort)
{
	if (to_sort->loc == TOP_B || to_sort->loc == BOTTOM_A
		|| to_sort->loc == BOTTOM_B)
	{
		move_from_to(data, to_sort->loc, TOP_A);
		move_from_to(data, to_sort->loc, TOP_A);
	}
	if (data->a->top->value > data->a->top->next->value)
		sa(data->a);
	to_sort->size -= 2;
}

void	sort_chunk_one(t_data *data, t_chunk *to_sort)
{
	if (to_sort->loc == TOP_B || to_sort->loc == BOTTOM_A
		|| to_sort->loc == BOTTOM_B)
		move_from_to(data, to_sort->loc, TOP_A);
	to_sort->size--;
}

void	sort_chunk_three(t_data *data, t_chunk *to_sort)
{
	int	max;

	max = chunk_max_value(data, to_sort);
	if (to_sort->loc == TOP_B || to_sort->loc == BOTTOM_A
		|| to_sort->loc == BOTTOM_B)
	{
		move_from_to(data, to_sort->loc, TOP_A);
		move_from_to(data, to_sort->loc, TOP_A);
		move_from_to(data, to_sort->loc, TOP_A);
		to_sort->loc = TOP_A;
	}
	sort_three_top_a(data, to_sort, max);
}

static void	sort_three_top_a(t_data *data, t_chunk *to_sort, int max)
{
	int	first;
	int	second;

	first = data->a->top->value;
	second = data->a->top->next->value;
	if (first == max)
	{
		sa(data->a);
		ra(data->a);
		sa(data->a);
		rra(data->a);
	}
	else if (second == max)
	{
		ra(data->a);
		sa(data->a);
		rra(data->a);
	}
	to_sort->size--;
	sort_chunk_two(data, to_sort);
}
