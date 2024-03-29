/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:50:37 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 17:44:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_int	temp;

	if (stk->size < 2)
		return ;
	temp = front(stk);
	stk->head.next->data = stk->head.next->next->data;
	stk->head.next->next->data = temp;
	return ;
}

void	swap_x(t_stack *stk)
{
	swap(stk);
	ft_printf("s%c\n", stk->name);
	return ;
}
