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
	t_arr arr;
	size_t i;

	if (stk->size < 2)
		return (FALSE);
	stack_to_arr(stk, &arr);
	selection_sort(&arr);
	i = -1;
	while (++i + 1 < arr.size)
	{
		if (arr.data[i] == arr.data[i + 1])
			return (TRUE);
	}
	free(arr.data);
	return (FALSE);
}

t_bool	is_asc_stack(t_stack *stk)
{
	t_arr	arr;
	t_data	min;
	size_t	i;
	size_t	min_i;

	stack_to_arr(stk, &arr);
	min = get_arr_min(&arr);
	i = -1;
	min_i = -1;
	while(++i < arr.size)
	{
		if(arr.data[i] == min)
			min_i = i;
	}
	i = -1;
	while(++i + 1 < arr.size)
	{
		if (arr.data[min_i] > arr.data[(min_i + 1)%arr.size])
			return (FALSE);
		min_i = (min_i + 1) % arr.size;
	}
	free(arr.data);
	return (TRUE);
}
