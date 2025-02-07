/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:54:05 by riyano            #+#    #+#             */
/*   Updated: 2025/01/27 18:06:29 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stddef.h>
#include <stdlib.h>

void	stack_push_top(t_stack *stack, t_node *new_node)
{
	if (!new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

void	stack_push_bottom(t_stack *stack, t_node *new_node)
{
	if (!new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
}

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*pop_node;

	if (stack->size == 0)
		return (NULL);
	pop_node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = pop_node->next;
		stack->top->prev = NULL;
	}
	pop_node->next = NULL;
	pop_node->prev = NULL;
	stack->size--;
	return (pop_node);
}

t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*pop_node;

	if (stack->size == 0)
		return (NULL);
	pop_node = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = pop_node->prev;
		stack->bottom->next = NULL;
	}
	pop_node->prev = NULL;
	pop_node->next = NULL;
	stack->size--;
	return (pop_node);
}
