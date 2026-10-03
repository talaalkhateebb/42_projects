/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <talkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:34:36 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/25 12:34:36 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int				data;
	int				index;
	struct node		*next;
}	t_node;

typedef struct stack
{
	t_node	*top;
}	t_stack;

void	ft_push(t_stack *s, int value);
void	push_node(t_stack *from, t_stack *to);
int		ft_pop(t_stack *s);
int		ft_atoi(const char *str);
int		get_moves(int pos, int size);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra_b(t_stack *a);
void	ra_b(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sort_2(t_stack *s);
void	sort_3(t_stack *s);
void	sort_5_4(t_stack *a, t_stack *b);
void	indexing(t_stack *s);
int		*fill_array(t_stack *s);
void	sort_arr(int *arr, int size);
void	assign_index(t_stack *s, int *arr, int size);
int		stack_size(t_stack *s);
int		get_chunk_size(int total_size);
int		find_max_index(t_stack *s);
int		find_position(t_stack *s, int index_to_find);
int		is_in_chunk(t_stack *s, int min_index, int max_index);
int		best_move_in_chunk(t_stack *s, int min_index, int max_index);
void	move_to_top_a(t_stack *a, int position);
void	move_to_top_b(t_stack *b, int position);
void	push_to_b_chunks(t_stack *a, t_stack *b, int total_size);
void	push_back_to_a(t_stack *a, t_stack *b);
void	sort_chunks(t_stack *a, t_stack *b);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *s, int value);
void	error_exit(t_stack *a);
void	free_stack(t_stack *s);
int		is_sorted(t_stack *s);

#endif
