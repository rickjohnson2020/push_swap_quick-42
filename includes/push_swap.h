/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:19:52 by riyano            #+#    #+#             */
/*   Updated: 2025/01/27 17:36:05 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef struct s_split
{
	t_chunk	max;
	t_chunk	mid;
	t_chunk	min;
}	t_split;

t_node	*create_node(int value);
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_data(t_data *data);
t_data	*init_data(int *arr, int size);
void	stack_push_top(t_stack *stack, t_node *new_node);
void	stack_push_bottom(t_stack *stack, t_node *new_node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);
void	quick_sort_arr(int *arr, int l, int r);
void	sort_three_a(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	error_and_exit(void);
void	push_smallest_to_b(t_stack *a, t_stack *b);
void	quick_sort_stack(t_data *data);
void	sort_chunk_three(t_data *data, t_chunk *to_sort);
void	sort_chunk_two(t_data *data, t_chunk *to_sort);
void	sort_chunk_one(t_data *data, t_chunk *to_sort);
int		move_from_to(t_data *data, t_loc from, t_loc to);
int		chunk_max_value(t_data *data, t_chunk *chunk);
t_node	*get_current_node(t_data *data, t_loc loc);
t_node	*get_next_node(t_node *node, t_loc loc);
void	init_dest(t_split *dest);
void	set_pivots(t_loc loc, int size, int *pivot_1, int *pivot_2);
void	set_split_loc(t_loc loc, t_chunk *max, t_chunk *mid, t_chunk *min);
int		chunk_max_value(t_data *data, t_chunk *chunk);
void	sort_main(t_data *data);
int		main(int argc, char **argv);
void	normalize_numbers(int *arr, int *sorted, int n);
int		free_split_and_error(char **split);
void	free_arr_and_exit(int *arr);

#endif
