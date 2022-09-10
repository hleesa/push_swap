/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:39:00 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 13:57:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_empty(t_stack *stk)
{
	return (stk->size == 0);
}

t_bool	is_duplicate(t_stack *stk)
{
	t_bool	ret;
	t_arr	arr;
	size_t	i;

	ret = FALSE;
	if (stk->size < 2)
		return (ret);
	stack_to_arr(stk, &arr);
	selection_sort(&arr);
	i = -1;
	while (++i + 1 < arr.size)
	{
		if (arr.data[i] == arr.data[i + 1])
		{
			ret = TRUE;
			break ;
		}
	}
	free(arr.data);
	return (ret);
}

t_bool	is_asc_stack(t_stack *stk)
{
	t_bool	ret;
	size_t	i;
	size_t	min_i;
	t_arr	arr;

	stack_to_arr(stk, &arr);
	min_i = get_arr_min_idx(&arr);
	i = -1;
	ret = TRUE;
	while (++i + 1 < arr.size)
	{
		if (arr.data[min_i] > arr.data[(min_i + 1) % arr.size])
		{
			ret = FALSE;
			break ;
		}
		min_i = (min_i + 1) % arr.size;
	}
	free(arr.data);
	return (ret);
}

t_bool	is_rotate(t_stack *a, t_lis *is_lis)
{
	t_arr	arr;
	size_t	i;
	ssize_t	begin;
	ssize_t	end;

	stack_to_arr(a, &arr);
	begin = -1;
	end = -1;
	i = -1;
	while (++i < arr.size)
	{
		if (is_lis->arr.data[arr.data[i]])
			continue ;
		if (begin == -1)
			begin = i;
		else
			end = i;
	}
	free(arr.data);
	if (end == -1)
		end = begin;
	if (end < (ssize_t)a->size - begin + 1)
		return (TRUE);
	return (FALSE);
}
