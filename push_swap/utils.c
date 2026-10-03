/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:40 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 13:03:40 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *s, int value)
{
	t_node	*tmp;

	tmp = s->top;
	while (tmp)
	{
		if (tmp->data == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
}

void	error_exit(t_stack *a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
