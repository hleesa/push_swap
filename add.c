/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:23:08 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:31:14 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_back(t_stack *stk, t_data data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return (FALSE);
	new_node->next = stk->tail;
	new_node->prev = stk->tail->prev;
	stk->tail->prev->next = new_node;
	stk->tail->prev = new_node;
	++stk->size;
	return (TRUE);
}

t_bool	add_front(t_stack *stk, t_data data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return (FALSE);
	new_node->next = stk->head->next;
	new_node->prev = stk->head;
	stk->head->next->prev = new_node;
	stk->head->next = new_node;
	++stk->size;
	return (TRUE);
}

t_node	*create_node(t_data data)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (ret == 0)
		return (NULL);
	ret->data = data;
	return (ret);
}
