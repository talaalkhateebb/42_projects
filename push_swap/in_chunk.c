/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:30 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:30 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(t_stack *s, int min_index, int max_index)
{
	t_node	*tmp;

	tmp = s->top;
	while (tmp)
	{
		if (tmp->index >= min_index && tmp->index <= max_index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
