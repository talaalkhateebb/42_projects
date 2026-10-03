/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:28 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:34:28 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_overflow(const char *str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && num > 2147483648))
			return (0);
		i++;
	}
	return (1);
}

static void	validate_and_push(t_stack *a, char *arg)
{
	int	val;

	if (!is_valid_number(arg))
		error_exit(a);
	if (!check_int_overflow(arg))
		error_exit(a);
	val = ft_atoi(arg);
	if (has_duplicate(a, val))
		error_exit(a);
	ft_push(a, val);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc < 2)
		return (0);
	a.top = NULL;
	b.top = NULL;
	i = argc - 1;
	while (i > 0)
		validate_and_push(&a, argv[i--]);
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	indexing(&a);
	sort_chunks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
