/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:36 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:36 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *s)
{
	int		size;
	int		*arr;

	size = stack_size(s);
	arr = fill_array(s);
	if (!arr)
		return ;
	sort_arr(arr, size);
	assign_index(s, arr, size);
	free(arr);
}
