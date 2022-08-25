/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:24:30 by salee2            #+#    #+#             */
/*   Updated: 2022/08/24 13:24:33 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_front(t_stack *stk)
{
	t_node *front;

	front = stk->head->next;
	stk->head->next = front->next;
	front->next->prev = stk->head;
	free(front);
	--stk->size;
	return ;
}
