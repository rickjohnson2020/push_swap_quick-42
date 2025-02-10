/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:39:22 by riyano            #+#    #+#             */
/*   Updated: 2025/02/05 19:40:17 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stddef.h>
#include <stdlib.h>

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	free_all_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_data	*init_data(int *arr, int size)
{
	t_data	*data;
	t_node	*node;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	if (!data->a || !data->b)
	{
		free(data);
		return (NULL);
	}
	init_stack(data->a);
	init_stack(data->b);
	i = 0;
	while (i < size)
	{
		node = create_node(arr[i++]);
		stack_push_bottom(data->a, node);
	}
	return (data);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->a)
		{
			free_all_nodes(data->a);
			free(data->a);
		}
		if (data->b)
		{
			free_all_nodes(data->b);
			free(data->b);
		}
		free(data);
	}
}
