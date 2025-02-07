/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:31:56 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 17:03:02 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	split_chunk(t_data *data, t_chunk *to_split, t_split *dest)
{
	int		pivot_1;
	int		pivot_2;
	int		max_value;
	t_node	*cur;
	t_node	*next;

	init_dest(dest);
	set_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	set_split_loc(to_split->loc, &dest->max, &dest->mid, &dest->min);
	cur = get_current_node(data, to_split->loc);
	max_value = chunk_max_value(data, to_split);
	while (to_split->size-- > 0)
	{
		next = get_next_node(cur, to_split->loc);
		if (cur->value > max_value - pivot_2)
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
		else if (cur->value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
		cur = next;
		//TODO: Check
		//if (!cur)
		//	break ;
	}
}

//TODO:
static void	rec_chunk_sort(t_data *data, t_chunk *to_sort)
{
	t_split	dest;

//	if (to_sort->loc == BOTTOM_A && data->a->size == to_sort->size)
//		to_sort->loc = TOP_A;
//	if (to_sort->loc == BOTTOM_B && data->b->size == to_sort->size)
//		to_sort->loc = TOP_B;
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_chunk_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_chunk_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_chunk_one(data, to_sort);
		return ;
	}
	split_chunk(data, to_sort, &dest);
	rec_chunk_sort(data, &dest.max);
	rec_chunk_sort(data, &dest.mid);
	rec_chunk_sort(data, &dest.min);
}

void	quick_sort_stack(t_data *data)
{
	t_chunk	chunk;

	if (!data)
		return ;
	chunk.loc = TOP_A;
	chunk.size = data->a->size;
	rec_chunk_sort(data, &chunk);
}
