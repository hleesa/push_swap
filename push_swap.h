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
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define TABLE_SIZE 7

typedef int t_bool;
typedef int t_data;

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
	t_data 	*data;
	size_t	size;
}	t_arr;

typedef	struct s_lis
{
	t_arr	arr;
	size_t	size;
}	t_lis;

typedef struct s_range
{
	t_data	begin;
	t_data	end;
}	t_range;

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


t_bool	add_back(t_stack *stk, t_data data);
t_bool	add_front(t_stack *stk, t_data data);
t_node	*create_node(t_data data);
size_t	max(size_t a, size_t b);
int		*get_sorted_arr(t_stack *stk, size_t *len);
void	init(t_stack *a, t_stack *b, int argc, char ***argv);
t_bool	is_empty(t_stack *stk);
t_bool	is_duplicate(t_stack *stk);
t_bool	is_sorted(t_stack *a, t_stack *b);
void	stack_to_arr(t_stack *stk, t_arr *arr);
void	get_lis(t_stack *stk, t_arr *memo, t_arr *from);
void	get_is_lis(t_arr *arr, t_arr *memo, t_arr *from, t_arr *is_lis);
void	stack_to_is_lis(t_stack *stk, t_lis *is_lis);
void	move_a_to_b(t_stack *a, t_stack *b, int *sorted_arr, int arr_len);
void	move_b_to_a(t_stack *a, t_stack *b, int *sorted_arr, int arr_len);
t_data	back(t_stack *stk);
t_data	front(t_stack *stk);
t_data	front_second(t_stack *stk);
void	pop_back(t_stack *stk);
void	pop_front(t_stack *stk);
void	preprocess_stack(t_stack *a);
int		print_error(void);
void	push_dst(t_stack *src, t_stack *dst);
void	push_swap(t_stack *a, t_stack *b);
void	reverse_rotate_repeat_x(t_stack *stk, int num_of_repeat);
void	rotate_repeat_x(t_stack *stk, int num_of_repeat);
void	rotate_x(t_stack *stk);
void	sel_sort(t_stack *stk);
void	selection_sort(t_arr *arr);
void	sort_a_half(t_stack *a, t_stack *b);
void	sort_b_half(t_stack *a, t_stack *b);
void	swap_x(t_stack *stk);
void	push_a(t_stack *a, t_stack *b);

t_arr 	*create_rotate_table();
int	get_num_of_rotate(t_arr *arr, t_data target);
t_data	get_arr_max(t_arr *arr);

size_t min(size_t a, size_t b);

void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, int num_of_repeat);
void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, int num_of_repeat);

void	ss(t_stack *a, t_stack *b);

void	reverse_rotate_x(t_stack *stk);
t_bool	is_over_two_thirds(t_data num, t_data total);
void	push_b(t_stack *a, t_stack *b, t_arr *arr, size_t range);
void	push_b_half(t_stack *a, t_stack *b);

#include <stdio.h>

void print_stack_a_b(t_stack *a, t_stack *b);


#endif //PUSH_SWAP_H
