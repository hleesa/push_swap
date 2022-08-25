/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:54:05 by salee2            #+#    #+#             */
/*   Updated: 2022/08/24 11:54:06 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_back(t_stack *stk)
{
	t_node *back;

	back = stk->tail->prev;
	stk->tail->prev = back->prev;
	back->prev->next = stk->tail;
	free(back);
	--stk->size;
	return ;
}
