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
	stk->head = (t_node*) (0, NULL, &stk->tail);
	stk->tail = (t_node*) (0, &stk->head, NULL);
	stk->size = 0;
	return;
}