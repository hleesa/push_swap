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
	t_data	temp;

	if (stk->size < 2)
		return ;
	temp = stk->head->next->data;
	pop_front(stk);
	add_back(stk, temp);
	return ;
}

void	rotate_x(t_stack *stk)
{
	rotate(stk);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stk->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	rotate_repeat_x(t_stack *stk, int repeats)
{
	int	i;

	i = 0;
	while (i < repeats)
	{
		rotate_x(stk);
		++i;
	}
	return ;
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return ;
}

void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, int repeats)
{
	int	i;

	i = 0;
	while (i < repeats)
	{
		rotate_rotate(a, b);
		++i;
	}
	return ;
}
