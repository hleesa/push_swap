/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:10:50 by salee2            #+#    #+#             */
/*   Updated: 2022/08/25 14:10:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_integer	temp;

	if (stk->size < 2)
		return ;
	temp = stk->head.next->data;
	pop_front(stk);
	add_back(stk, temp);
	return ;
}

void	rotate_x(t_stack *stk)
{
	rotate(stk);
	ft_printf("r%c\n", stk->name);
	return ;
}

void	rotate_repeat_x(t_stack *stk, size_t repeats)
{
	size_t	i;

	i = -1;
	while (++i < repeats)
		rotate_x(stk);
	return ;
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return ;
}

void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, size_t repeats)
{
	size_t	i;

	i = -1;
	while (++i < repeats)
		rotate_rotate(a, b);
	return ;
}
