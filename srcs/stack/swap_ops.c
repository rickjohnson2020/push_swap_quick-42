/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:42:31 by riyano            #+#    #+#             */
/*   Updated: 2025/01/29 15:42:47 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

static void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack_pop_top(stack);
	second = stack_pop_top(stack);
	stack_push_top(stack, first);
	stack_push_top(stack, second);
}

void	sa(t_stack *a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}
