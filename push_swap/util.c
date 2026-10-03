/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:34 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:04:27 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_stack *s)
{
	t_node	*tmp;
	int		value;

	if (!s->top)
		return (-1);
	tmp = s->top;
	value = tmp->data;
	s->top = s->top->next;
	free(tmp);
	return (value);
}

void	push_node(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (!from->top)
		return ;
	tmp = from->top;
	from->top = from->top->next;
	tmp->next = to->top;
	to->top = tmp;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}

int	get_moves(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}
