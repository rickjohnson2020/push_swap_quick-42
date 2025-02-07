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

void	sort_main(t_data *data)
{
	if (data->a->size == 2)
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
