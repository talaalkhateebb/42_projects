/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:06 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:06 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cal_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

static int	is_better_move(int cost, int best_cost, int index, int best_index)
{
	if (cost < best_cost)
		return (1);
	if (cost == best_cost && index < best_index)
		return (1);
	return (0);
}

static void	update_best(int pos, int size, t_node *tmp, int *best)
{
	if (is_better_move(cal_cost(pos, size), best[0],
			tmp->index, best[1]))
	{
		best[0] = cal_cost(pos, size);
		best[1] = tmp->index;
		best[2] = pos;
	}
}

int	best_move_in_chunk(t_stack *s, int min_index, int max_index)
{
	t_node	*tmp;
	int		pos;
	int		size;
	int		best[3];

	tmp = s->top;
	pos = 0;
	size = stack_size(s);
	best[0] = size + 1;
	best[1] = max_index + 1;
	best[2] = -1;
	while (tmp)
	{
		if (tmp->index >= min_index && tmp->index <= max_index)
			update_best(pos, size, tmp, best);
		pos++;
		tmp = tmp->next;
	}
	return (best[2]);
}
