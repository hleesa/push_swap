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

	temp = stk->head->next->data;
	pop_front(stk);
	add_back(stk, temp);
	return;
}

void	rotate_x(t_stack *stk)
{
	rotate(stk);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stk->name, 1);
	ft_putchar_fd('\n', 1);
	return;
}

void	rotate_repeat_x(t_stack *stk, int num_of_repeat)
{
	int	i;

	i = 0;
	while(i <num_of_repeat)
	{
		rotate_x(stk);
		++i;
	}
	return;
}

void	rotate_rotate_repeat_x(t_stack *a, t_stack *b, int num_of_repeat)
{
	int	i;

	i = 0;
	while(i <num_of_repeat)
	{
		rotate_x(a);
		rotate_x(b);
		++i;
	}
	return;
}
