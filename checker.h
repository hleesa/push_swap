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

# include "push_swap.h"
# define STDIN 0
# define INSTR_SIZE 11

enum e_instructions
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
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

#endif //CHECKER_H
