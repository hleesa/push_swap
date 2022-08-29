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

t_bool is_duplicate(int *sorted_arr, int arr_len)
{
	int	i;

	if (arr_len == 0)
		return (0);
	i = 0;
	while (i + 1 < arr_len)
	{
		if (sorted_arr[i] == sorted_arr[i+1])
			return (1);
		++i;
	}
	return (0);
}

t_bool	is_sorted(t_stack *a, t_stack *data)
{
	t_node	*a_cur;
	t_node	*d_cur;

	if (a->size != data->size)
		return (0);
	a_cur = a->head->next;
	d_cur = data->head->next;
	while(a_cur != a->tail)
	{
		if(a_cur->data != d_cur->data)
			return (0);
		a_cur = a_cur->next;
		d_cur = d_cur->next;
	}
	return (1);
}
/*
t_bool	is_sorted_pos(t_stack *src, t_stack *dst)
{
	if
}
 */