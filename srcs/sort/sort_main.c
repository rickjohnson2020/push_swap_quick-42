/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:26:23 by riyano            #+#    #+#             */
/*   Updated: 2025/02/07 17:00:31 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_sorted(t_data *data);

void	sort_main(t_data *data)
{
	if (data->a->size <= 1 || is_sorted(data))
		return ;
	else if (data->a->size == 2)
	{
		if (data->a->top->value > data->a->bottom->value)
			sa(data->a);
	}
	else if (data->a->size == 3)
		sort_three_a(data->a);
	else if (data->a->size == 4)
		sort_four(data->a, data->b);
	else if (data->a->size == 5)
		sort_five(data->a, data->b);
	else
		quick_sort_stack(data);
}

static int	is_sorted(t_data *data)
{
	int		size;
	t_node	*cur;
	t_node	*next;
	int		sorted;
	t_node	*temp;

	sorted = 1;
	cur = data->a->top;
	next = data->a->top->next;
	size = data->a->size;
	while (size-- > 1)
	{
		if (cur->value > next->value)
		{
			sorted = 0;
			break ;
		}
		temp = next;
		cur = next;
		next = temp->next;
		if (!next)
			break ;
	}
	return (sorted);
}
