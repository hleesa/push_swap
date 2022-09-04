/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:15:18 by salee2            #+#    #+#             */
/*   Updated: 2022/08/25 14:15:19 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stk)
{
	t_data	temp;

	temp = stk->tail->prev->data;
	pop_back(stk);
	add_front(stk, temp);
	return;
}

void	reverse_rotate_x(t_stack *stk)
{
	reverse_rotate(stk);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stk->name, 1);
	ft_putchar_fd('\n', 1);
	return;
}

void	reverse_rotate_repeat_x(t_stack *stk, int num_of_repeat)
{
	int	i;

	i = 0;
	while(i < num_of_repeat)
	{
		reverse_rotate_x(stk);
		++i;
	}
	return;
}

void	reverse_rotate_rotate_repeat_x(t_stack *a, t_stack *b, int num_of_repeat)
{
	int	i;

	i = 0;
	while(i < num_of_repeat)
	{
		reverse_rotate_x(a);
		reverse_rotate_x(b);
		++i;
	}
	return;
}