/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:41:47 by riyano            #+#    #+#             */
/*   Updated: 2025/01/29 15:41:57 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = stack_pop_top(a);
	stack_push_top(b, temp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = stack_pop_top(b);
	stack_push_top(a, temp);
	write(1, "pa\n", 3);
}
