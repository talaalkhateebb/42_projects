/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:44 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:05:09 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_element_in_chunk(t_stack *a, t_stack *b, int mid_index)
{
	pb(a, b);
	if (stack_size(b) > 1 && b->top->index < mid_index)
		rb(b);
}

static void	process_chunk(t_stack *a, t_stack *b, int range[3])
{
	int	position;

	while (is_in_chunk(a, range[0], range[1]))
	{
		if (a->top->index >= range[0] && a->top->index <= range[1])
		{
			handle_element_in_chunk(a, b, range[2]);
		}
		else
		{
			position = best_move_in_chunk(a, range[0], range[1]);
			if (position == -1)
				break ;
			move_to_top_a(a, position);
		}
	}
}

static void	init_chunk_range(int range[3], int chunk, int size, int total)
{
	range[0] = chunk * size;
	range[1] = (chunk + 1) * size - 1;
	if (range[1] >= total)
		range[1] = total - 1;
	range[2] = (range[0] + range[1]) / 2;
}

void	push_to_b_chunks(t_stack *a, t_stack *b, int total_size)
{
	int	chunk_size;
	int	current_chunk;
	int	num_chunks;
	int	range[3];

	chunk_size = get_chunk_size(total_size);
	num_chunks = (total_size + chunk_size - 1) / chunk_size;
	current_chunk = 0;
	while (current_chunk < num_chunks && stack_size(a) > 0)
	{
		init_chunk_range(range, current_chunk, chunk_size, total_size);
		process_chunk(a, b, range);
		current_chunk++;
	}
}
