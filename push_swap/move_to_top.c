/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:54 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:54 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stack *s, int position,
				void (*rotate)(t_stack *), void (*rrotate)(t_stack *))
{
	int	size;

	size = stack_size(s);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rotate(s);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rrotate(s);
			position++;
		}
	}
}

void	move_to_top_a(t_stack *a, int position)
{
	move_to_top(a, position, ra, rra);
}

void	move_to_top_b(t_stack *b, int position)
{
	move_to_top(b, position, rb, rrb);
}
