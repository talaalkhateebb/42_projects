/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:13 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:03:13 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *s)
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

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_position(a);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(a);
	size = stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	sort_5_4(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
