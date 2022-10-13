/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:37 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 14:25:15 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# define STDERR 2
# define TABLE_SIZE 7

typedef int	t_bool;
typedef int	t_int;

typedef struct s_node
{
	t_int			data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char	name;
	size_t	size;
	t_node	head;
	t_node	tail;
}	t_stack;

typedef struct s_arr
{
	t_int	*data;
	size_t	size;
}	t_arr;

typedef struct s_lis
{
	t_arr	arr;
	size_t	size;
}	t_lis;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_rotate
{
	RA,
	RRA,
	RB,
	RRB,
	RR,
	RRR,
	SUM
};

enum e_rotate_type
{
	RA_RB,
	RRA_RB,
	RA_RRB,
	RRA_RRB
};

void	add_back(t_stack *stk, t_int data);
void	add_front(t_stack *stk, t_int data);
t_node	*create_node(t_int data);
void	free_stack(t_stack *stk);
size_t	min(size_t a, size_t b);
t_int	get_arr_max(t_arr *arr);
t_int	get_arr_min(t_arr *arr);
size_t	get_arr_min_idx(t_arr *arr);
t_int	get_num_of_rotate(t_arr *arr, t_int target);
void	init(t_stack *a, t_stack *b, int argc, char ***argv);
void	init_set_type_table(void (*set_type_table[4])(t_int*, t_int*));
t_bool	is_empty(t_stack *stk);
t_bool	is_duplicate(t_stack *stk);
t_bool	is_asc_stack(t_stack *stk);
t_bool	is_rotate(t_stack *a, t_lis *is_lis);
void	stack_to_is_lis(t_stack *stk, t_lis *is_lis);
void	get_lis_memo_from(t_stack *stk, t_arr *memo, t_arr *from);
size_t	get_lis_len(t_arr *memo);
t_int	back(t_stack *stk);
t_int	front(t_stack *stk);
void	pop_back(t_stack *stk);
void	pop_front(t_stack *stk);
int		print_error(void);
void	push_dst(t_stack *src, t_stack *dst);
void	push_b_not_lis(t_stack *a, t_stack *b, t_lis *is_lis);
void	push_swap(t_stack *a, t_stack *b);
void	reverse_rotate_x(t_stack *stk);
void	reverse_rotate_repeat_x(t_stack *stk, size_t repeats);
void	reverse_rotate_reverse_rotate(t_stack *a, t_stack *b);
void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, size_t repeats);
void	rotate_x(t_stack *stk);
void	rotate_repeat_x(t_stack *stk, size_t repeats);
void	rotate_rotate(t_stack *a, t_stack *b);
void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, size_t repeats);
void	set_table(t_int *table, t_int val);
void	set_table_ra_rb(t_int *src, t_int *dst);
void	set_table_rra_rb(t_int *src, t_int *dst);
void	set_table_ra_rrb(t_int *src, t_int *dst);
void	set_table_rra_rrb(t_int *src, t_int *dst);
void	selection_sort(t_arr *arr);
void	five_sort(t_stack *a, t_stack *b);
void	last_sort(t_stack *stk);
void	stack_to_arr(t_stack *stk, t_arr *arr);
void	preprocess_stack(t_stack *a);
void	rotate_stack(t_stack *a, t_stack *b, t_int *table);
void	swap_x(t_stack *stk);
void	get_min_rotate_table(t_stack *a, t_stack *b, t_int *min_table, \
void (*set_type_table[4])(t_int*, t_int*));

#endif //PUSH_SWAP_H
