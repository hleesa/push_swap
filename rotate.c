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

void	rotate_x(t_stack *stk, char stk_name)
{
	rotate(stk);
	write(1, "r", 1);
	write(1, &stk_name, 1);
	write(1, "\n", 1);
	return;
}

void	rotate_repeat_x(t_stack *stk, char stk_name, int num_of_repeat)
{
	int	i;

	i = 0;
	while(i <num_of_repeat)
	{
		rotate_x(stk, stk_name);
		++i;
	}
	return;
}