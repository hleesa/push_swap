/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:22:53 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:22:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stk)
{
	stk->head = create_node(0);
	stk->tail = create_node(0);
	if (stk->head == NULL || stk->tail == NULL)
		return;
	stk->head->prev = NULL;
	stk->head->next = stk->tail;
	stk->tail->prev = stk->head;
	stk->tail->next = NULL;
	stk->size = 0;
	return;
}

void	init_stack_arg(t_stack *stk, int argc, char ***argv)
{
	init_stack(stk);
	while(--argc)
		add_front(stk, ft_atoi((*argv)[argc]));
	return;
}