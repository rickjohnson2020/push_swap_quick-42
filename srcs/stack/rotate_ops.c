/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:43:27 by riyano            #+#    #+#             */
/*   Updated: 2025/01/29 15:44:53 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

static void	rotate_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack_pop_top(stack);
	stack_push_bottom(stack, temp);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}
