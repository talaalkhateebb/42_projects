/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:01 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:06:23 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	push_node(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push_node(b, a);
	write(1, "pa\n", 3);
}

void	ra_b(t_stack *a)
{
	t_node	*first;
	t_node	*tmp;

	if (!a->top || !a->top->next)
		return ;
	tmp = a->top;
	first = a->top;
	while (tmp->next)
		tmp = tmp->next;
	a->top = first->next;
	tmp->next = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	ra_b(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	ra_b(b);
	write(1, "rb\n", 3);
}
