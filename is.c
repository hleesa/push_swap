/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:39:00 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:39:08 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_empty(t_stack *stk)
{
	return stk->size == 0;
}

t_bool is_duplicate(t_stack *stk)
{
	t_node	*cur;

	if (stk->size == 0)
		return (0);
	cur = stk->head->next;
	while (cur->next != stk->tail)
	{
		if (cur->data == cur->next->data)
			return (1);
		cur = cur->next;
	}
	return (0);
}

t_bool	is_sorted_stack(t_stack *stk, t_bool is_asc)
{
	t_node	*cur;

	if (stk->size < 2)
		return (1);
	cur = stk->head->next;
	while(cur->next != stk->tail)
	{
		if (is_asc)
		{
			if (cur->data > cur->next->data)
				return (0);
		}
		else
		{
			if (cur->data < cur->next->data)
				return (0);
		}
		cur = cur->next;
	}
	return (1);
}

t_bool	is_sorted(t_stack *a, t_stack *b)
{
	return (is_sorted_stack(a, TRUE) && is_sorted_stack(b, FALSE));
}