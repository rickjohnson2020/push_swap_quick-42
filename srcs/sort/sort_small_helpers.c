/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:12 by riyano            #+#    #+#             */
/*   Updated: 2025/01/29 15:20:47 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_smallest_idx(t_stack *a)
{
	int		i;
	int		min_idx;
	int		min_val;
	t_node	*cur;

	i = 0;
	min_idx = 0;
	cur = a->top;
	min_val = cur->value;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_idx);
}

static void	rotate_minimal(t_stack *a, int idx, int size)
{
	int	i;

	i = 0;
	if (idx <= size / 2)
	{
		while (i < idx)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < (size - idx))
		{
			rra(a);
			i++;
		}
	}
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	idx;
	int	size;

	idx = find_smallest_idx(a);
	size = a->size;
	rotate_minimal(a, idx, size);
	pb(a, b);
}
