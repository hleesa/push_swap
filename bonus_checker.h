/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:21:12 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 11:21:12 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# define STDIN 0
# define INSTR_SIZE 11

typedef int	t_bool;
typedef int	t_integer;

typedef struct s_node
{
	t_integer		data;
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
	t_integer	*data;
	size_t	size;
}	t_arr;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_instructions
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	swap(t_stack *stk);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stk);
void	swap_a(t_stack *a, t_stack *b);
void	swap_b(t_stack *a, t_stack *b);
void	swap_swap(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a, t_stack *b);
void	rotate_b(t_stack *a, t_stack *b);
void	rotate_rotate_bonus(t_stack *a, t_stack *b);
void	reverse_rotate_a(t_stack *a, t_stack *b);
void	reverse_rotate_b(t_stack *a, t_stack *b);
void	reverse_rotate_reverse_rotate_bonus(t_stack *a, t_stack *b);
void	checker(t_stack *a, t_stack *b);

t_bool	is_asc_stack(t_stack *stk);
t_integer	front(t_stack *stk);
void	init(t_stack *a, t_stack *b, int argc, char ***argv);
t_bool	is_duplicate(t_stack *stk);
void	free_stack(t_stack *stk);
t_bool	is_empty(t_stack *stk);
void	add_back(t_stack *stk, t_integer data);
void	add_front(t_stack *stk, t_integer data);
void	pop_back(t_stack *stk);
void	stack_to_arr(t_stack *stk, t_arr *arr);
void	init_stack(t_stack *stk, char name);
void	init_stack_arg(t_stack *stk, int argc, char ***argv);
void	preprocess_stack(t_stack *a);
void	selection_sort(t_arr *arr);

#endif //CHECKER_H
