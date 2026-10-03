/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:13 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:34:13 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *s, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->index = -1;
	new_node->next = s->top;
	s->top = new_node;
}

void	ft_swap(t_stack *s)
{
	int	tmp_data;
	int	tmp_index;

	if (!s->top || !s->top->next)
		return ;
	tmp_data = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp_data;
	tmp_index = s->top->index;
	s->top->index = s->top->next->index;
	s->top->next->index = tmp_index;
}

void	sa(t_stack *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
