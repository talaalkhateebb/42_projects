/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:19 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:19 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(t_stack *s)
{
	int		size;
	int		*arr;
	t_node	*tmp;
	int		i;

	i = 0;
	size = stack_size(s);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = s->top;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
