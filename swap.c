/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:50:37 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:05:43 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_data	temp;

	if (stk->size < 2)
		return ;
	temp = front(stk);
	stk->head->next->data = stk->head->next->next->data;
	stk->head->next->next->data = temp;
	return ;
}

void	swap_x(t_stack *stk)
{
	swap(stk);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stk->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return ;
}
