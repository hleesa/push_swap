/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:15:18 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:13:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stk)
{
	if (stk->size < 2)
		return ;
	add_front(stk, back(stk));
	pop_back(stk);
	return ;
}

void	reverse_rotate_x(t_stack *stk)
{
	reverse_rotate(stk);
	ft_printf("rr%c\n", stk->name);
	return ;
}

void	reverse_rotate_repeat_x(t_stack *stk, size_t repeats)
{
	size_t	i;

	i = -1;
	while (++i < repeats)
		reverse_rotate_x(stk);
	return ;
}

void	reverse_rotate_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	return ;
}

void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, size_t repeats)
{
	size_t	i;

	i = -1;
	while (++i < repeats)
		reverse_rotate_reverse_rotate(a, b);
	return ;
}
