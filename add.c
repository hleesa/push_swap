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

void	add_back(t_stack *stk, t_integer data)
{
	t_node	*new_node;

	new_node = create_node(data);
	new_node->next = &stk->tail;
	new_node->prev = stk->tail.prev;
	stk->tail.prev->next = new_node;
	stk->tail.prev = new_node;
	++stk->size;
	return ;
}

void	add_front(t_stack *stk, t_integer data)
{
	t_node	*new_node;

	new_node = create_node(data);
	new_node->next = stk->head.next;
	new_node->prev = &stk->head;
	stk->head.next->prev = new_node;
	stk->head.next = new_node;
	++stk->size;
	return ;
}

t_node	*create_node(t_integer data)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (ret == NULL)
		exit(ft_printf("Error\n"));
	ret->data = data;
	return (ret);
}
