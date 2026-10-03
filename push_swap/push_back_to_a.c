/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:19 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:05:54 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min_index;
	int		min_pos;
	int		pos;

	if (!s->top)
		return (-1);
	tmp = s->top;
	min_index = tmp->index;
	min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

static int	find_insert_position(t_stack *a, int index_b)
{
	t_node	*tmp;
	int		pos;
	int		target_pos;
	int		target_index;

	tmp = a->top;
	pos = 0;
	target_pos = 0;
	target_index = 2147483647;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (target_index == 2147483647)
		return (find_min_pos(a));
	return (target_pos);
}

static int	calculate_moves(t_stack *a, t_stack *b, int pos_b)
{
	t_node	*tmp;
	int		pos_a;
	int		i;

	tmp = b->top;
	i = 0;
	while (i < pos_b)
	{
		tmp = tmp->next;
		i++;
	}
	pos_a = find_insert_position(a, tmp->index);
	return (
		get_moves(pos_a, stack_size(a))
		+ get_moves(pos_b, stack_size(b))
	);
}

static int	find_cheapest_move(t_stack *a, t_stack *b)
{
	int	pos;
	int	best_pos;
	int	min_moves;
	int	moves;

	pos = 0;
	best_pos = 0;
	min_moves = 2147483647;
	while (pos < stack_size(b))
	{
		moves = calculate_moves(a, b, pos);
		if (moves < min_moves)
		{
			min_moves = moves;
			best_pos = pos;
		}
		pos++;
	}
	return (best_pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		best_pos;
	int		target_pos;
	int		i;

	while (stack_size(b) > 0)
	{
		best_pos = find_cheapest_move(a, b);
		tmp = b->top;
		i = 0;
		while (i < best_pos)
		{
			tmp = tmp->next;
			i++;
		}
		target_pos = find_insert_position(a, tmp->index);
		move_to_top_b(b, best_pos);
		move_to_top_a(a, target_pos);
		pa(a, b);
	}
	move_to_top_a(a, find_min_pos(a));
}
