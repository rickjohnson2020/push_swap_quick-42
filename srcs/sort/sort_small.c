/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:14:48 by riyano            #+#    #+#             */
/*   Updated: 2025/02/05 14:08:01 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_a(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && top < bot)
		sa(a);
	else if (top < mid && top > bot)
		rra(a);
	else if (top < bot && mid > bot)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && top > bot && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort_three_a(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three_a(a);
	pa(a, b);
	pa(a, b);
}
