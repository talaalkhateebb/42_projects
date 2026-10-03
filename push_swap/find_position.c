/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:25 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:25 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *s, int index_to_find)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = s->top;
	while (tmp)
	{
		if (tmp->index == index_to_find)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}
