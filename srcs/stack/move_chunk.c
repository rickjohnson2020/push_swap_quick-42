/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:06:14 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 17:22:18 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_top_a(t_data *data, t_loc to)
{
	if (to == BOTTOM_A)
		ra(data->a);
	else if (to == TOP_B)
		pb(data->a, data->b);
	else if (to == BOTTOM_B)
	{
		pb(data->a, data->b);
		rb(data->b);
	}
}

static void	move_bottom_a(t_data *data, t_loc to)
{
	if (to == TOP_A)
		rra(data->a);
	else if (to == TOP_B)
	{
		rra(data->a);
		pb(data->a, data->b);
	}
	else if (to == BOTTOM_B)
	{
		rra(data->a);
		pb(data->a, data->b);
		rb(data->b);
	}
}

static void	move_top_b(t_data *data, t_loc to)
{
	if (to == TOP_A)
		pa(data->a, data->b);
	else if (to == BOTTOM_A)
	{
		pa(data->a, data->b);
		ra(data->a);
	}
	else if (to == BOTTOM_B)
		rb(data->b);
}

static void	move_bottom_b(t_data *data, t_loc to)
{
	if (to == TOP_A)
	{
		rrb(data->b);
		pa(data->a, data->b);
	}
	else if (to == BOTTOM_A)
	{
		rrb(data->b);
		pa(data->a, data->b);
		ra(data->a);
	}
	else if (to == TOP_B)
		rrb(data->b);
}

int	move_from_to(t_data *data, t_loc from, t_loc to)
{
	if (from == TOP_A)
		move_top_a(data, to);
	else if (from == BOTTOM_A)
		move_bottom_a(data, to);
	else if (from == TOP_B)
		move_top_b(data, to);
	else if (from == BOTTOM_B)
		move_bottom_b(data, to);
	return (1);
}
