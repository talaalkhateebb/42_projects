/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:24 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:04:50 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min_index;
	int		min_pos;
	int		current_pos;

	if (!s->top)
		return (-1);
	tmp = s->top;
	min_index = tmp->index;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}

static void	sort_small_numbers(t_stack *a, t_stack *b)
{
	int	size;
	int	pushed;
	int	min_pos;

	size = stack_size(a);
	pushed = 0;
	while (size > 3)
	{
		min_pos = find_min_pos(a);
		move_to_top_a(a, min_pos);
		pb(a, b);
		pushed++;
		size--;
	}
	if (size == 3)
		sort_3(a);
	while (pushed > 0)
	{
		pa(a, b);
		pushed--;
	}
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5_4(a, b);
	else if (size <= 10)
		sort_small_numbers(a, b);
	else
	{
		push_to_b_chunks(a, b, size);
		push_back_to_a(a, b);
	}
}
