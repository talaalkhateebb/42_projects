/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:06 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:34:06 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	ra_b(a);
	ra_b(b);
	write(1, "rr\n", 3);
}

void	rra_b(t_stack *a)
{
	t_node	*prev;
	t_node	*curr;

	if (!a->top || !a->top->next)
		return ;
	curr = a->top;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = a->top;
	a->top = curr;
}

void	rra(t_stack *a)
{
	rra_b(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rra_b(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_b(a);
	rra_b(b);
	write(1, "rrr\n", 4);
}
