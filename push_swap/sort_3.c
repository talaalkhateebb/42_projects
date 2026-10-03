/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:07 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:03:07 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s)
{
	int	first;
	int	second;
	int	third;

	first = s->top->index;
	second = s->top->next->index;
	third = s->top->next->next->index;
	if (first < second && first < third && second > third)
	{
		rra(s);
		sa(s);
	}
	else if (first > second && first < third && second < third)
		sa(s);
	else if (first < second && first > third && third < second)
		rra(s);
	else if (first > second && first > third && second < third)
		ra(s);
	else if (first > second && first > third && second > third)
	{
		ra(s);
		sa(s);
	}
}
