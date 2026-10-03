/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:33:13 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:33:13 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int total_size)
{
	if (total_size <= 10)
		return (total_size);
	else if (total_size <= 100)
		return (25);
	else if (total_size <= 250)
		return (35);
	return (40);
}
