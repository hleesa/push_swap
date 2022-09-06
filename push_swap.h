/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:37 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:20:40 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define TABLE_SIZE 7

typedef int	t_bool;
typedef int	t_data;

typedef struct s_node
{
	t_data			data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char	name;
	size_t	size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_arr
{
	t_data	*data;
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

t_bool	add_back(t_stack *stk, t_data data);
t_bool	add_front(t_stack *stk, t_data data);
t_node	*create_node(t_data data);
size_t	max(size_t a, size_t b);
size_t	min(size_t a, size_t b);
t_data	get_arr_max(t_arr *arr);
t_data	get_arr_min(t_arr *arr);
int		get_num_of_rotate(t_arr *arr, t_data target);
void	init(t_stack *a, t_stack *b, int argc, char ***argv);
t_bool	is_empty(t_stack *stk);
t_bool	is_duplicate(t_stack *stk);
t_bool	is_asc_stack(t_stack *stk);
t_bool	is_rotate(t_stack *a, t_lis *is_lis);
void	stack_to_is_lis(t_stack *stk, t_lis *is_lis);
t_data	back(t_stack *stk);
t_data	front(t_stack *stk);
void	pop_back(t_stack *stk);
void	pop_front(t_stack *stk);
int		print_error(void);
void	push_dst(t_stack *src, t_stack *dst);
void	push_b_not_lis(t_stack *a, t_stack *b, t_lis *is_lis);
void	push_swap(t_stack *a, t_stack *b);

void	reverse_rotate_x(t_stack *stk);
void	reverse_rotate_repeat_x(t_stack *stk, int repeats);
void	reverse_rotate_reverse_rotate(t_stack *a, t_stack *b);
void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, int repeats);

void	reverse_rotate_repeat_x(t_stack *stk, int repeats);
void	reverse_rotate_reverse_rotate(t_stack *a, t_stack *b);
void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, int repeats);

void	rotate_x(t_stack *stk);
void	rotate_repeat_x(t_stack *stk, int repeats);
void	rotate_rotate(t_stack *a, t_stack *b);
void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, int repeats);

void	selection_sort(t_arr *arr);
void	last_sort(t_stack *stk);

void	stack_to_arr(t_stack *stk, t_arr *arr);
void	preprocess_stack(t_stack *a);
void	rotate_stack(t_stack *a, t_stack *b, int *table);

void	swap_x(t_stack *stk);
void	swap_swap(t_stack *a, t_stack *b);

int		get_min_type(int *table, int *min_table);
void	set_table(int *table, int val);
void	get_min_table(int *table, int *min_table);
void	get_min_rotate_table(t_stack *a, t_stack *b, int *min_table);

void	print_stack_a_b(t_stack *a, t_stack *b);
void	print_table(int *table);
//# include <stdio.h>

#endif //PUSH_SWAP_H
