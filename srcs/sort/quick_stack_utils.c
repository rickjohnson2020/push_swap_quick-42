/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:45:33 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 17:45:42 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_dest(t_split *dest)
{
	dest->max.size = 0;
	dest->mid.size = 0;
	dest->min.size = 0;
}

void	set_pivots(t_loc loc, int size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = size / 3 * 2;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && size < 15)
		*pivot_1 = size;
	if (loc == BOTTOM_B && size < 8)
		*pivot_2 = size / 2;
}

void	set_split_loc(t_loc loc, t_chunk *max, t_chunk *mid, t_chunk *min)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

int	chunk_max_value(t_data *data, t_chunk *chunk)
{
	t_node	*cur;
	int		max;
	int		i;

	i = chunk->size;
	cur = get_current_node(data, chunk->loc);
	max = 0;
	while (i-- > 0)
	{
		if (cur->value > max)
			max = cur->value;
		cur = get_next_node(cur, chunk->loc);
		if (!cur)
			break ;
	}
	return (max);
}
