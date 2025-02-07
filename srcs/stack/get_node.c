/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:41:16 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 17:41:21 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*get_current_node(t_data *data, t_loc loc)
{
	if (loc == TOP_A)
		return (data->a->top);
	else if (loc == BOTTOM_A)
		return (data->a->bottom);
	else if (loc == TOP_B)
		return (data->b->top);
	else if (loc == BOTTOM_B)
		return (data->b->bottom);
	else
		return (NULL);
}

t_node	*get_next_node(t_node *node, t_loc loc)
{
	if (!node)
		return (NULL);
	if (loc == BOTTOM_A || loc == BOTTOM_B)
		return (node->prev);
	return (node->next);
}
