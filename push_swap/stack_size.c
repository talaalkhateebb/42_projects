/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:29 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:03:29 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = s->top;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
