/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:23:08 by salee2            #+#    #+#             */
/*   Updated: 2022/08/24 11:23:28 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_back(t_stack *stk, t_data data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return FALSE;
	new_node->next = stk->tail;
	new_node->prev = stk->tail->prev;
	stk->tail->prev->next = new_node;
	stk->tail->prev = new_node;
	++stk->size;
	return TRUE;
}