/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:45:38 by riyano            #+#    #+#             */
/*   Updated: 2025/01/29 15:48:37 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

static void	r_rotate_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack_pop_bottom(stack);
	stack_push_top(stack, temp);
}

void	rra(t_stack *a)
{
	r_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	r_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	write(1, "rrr\n", 4);
}
