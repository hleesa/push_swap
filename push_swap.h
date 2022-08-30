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

t_bool	add_back(t_stack *stk, t_data data);
t_bool	add_front(t_stack *stk, t_data data);
t_node	*create_node(t_data data);
int		get_num_of_rotate(t_data top, t_stack *stk);
int	*get_sorted_arr(t_stack *stk, size_t *len);
void	init_stack(t_stack *stk, char name);
void	init_stack_arg(t_stack *stk, int argc, char ***argv, char name);
t_bool	is_empty(t_stack *stk);
t_bool 	is_duplicate(int *sorted_arr, int arr_len);
t_bool	is_sorted(t_stack *a, t_data *sort_arr, size_t arr_len);
void	move_a_to_b(t_stack *a, t_stack *b, int *sorted_arr, int arr_len);
void	move_b_to_a(t_stack *a, t_stack *b, int *sorted_arr, int arr_len);
t_data	back(t_stack *stk);
t_data	front(t_stack *stk);
t_data	front_second(t_stack *stk);
void	pop_back(t_stack *stk);
void	pop_front(t_stack *stk);
int		print_error(void);
void	push_dst(t_stack *src, t_stack *dst);
void	push_swap(t_stack *a, t_stack *b);
void	reverse_rotate_repeat_x(t_stack *stk, int num_of_repeat);
void	rotate_repeat_x(t_stack *stk, int num_of_repeat);
void	rotate_x(t_stack *stk);
void	sel_sort(t_stack *stk);
void	selection_sort(int *data, size_t len);
void	sort_a_half(t_stack *a, t_stack *b);
void	sort_b_half(t_stack *a, t_stack *b);
void	swap_x(t_stack *stk);
void	ss(t_stack *a, t_stack *b);



#include <stdio.h>
void print_stack(t_stack *stk);

#endif //PUSH_SWAP_H
