/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:47:49 by salee2            #+#    #+#             */
/*   Updated: 2022/08/24 11:47:50 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_front(t_stack *stk, t_data data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return FALSE;
	new_node->next = stk->head->next;
	new_node->prev = stk->head;
	stk->head->next->prev = new_node;
	stk->head->next = new_node;
	++stk->size;
	return TRUE;
}