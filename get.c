/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:12:44 by salee2            #+#    #+#             */
/*   Updated: 2022/08/27 14:12:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
size_t min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

t_data	get_arr_max(t_arr *arr)
{
	t_data ret;
	size_t i;

	i = -1;
	ret = INT_MIN;
	while(++i < arr->size)
	{
		if (arr->data[i] > ret)
			ret = arr->data[i];
	}
	return (ret);
}

t_data	get_arr_min(t_arr *arr)
{
	t_data ret;
	size_t i;

	i = -1;
	ret = INT_MAX;
	while(++i < arr->size)
	{
		if (arr->data[i] < ret)
			ret = arr->data[i];
	}
	return (ret);
}

int	num_of_rotate(t_data top, t_stack *stk)
{
	int		ret;
	t_node	*cur;

	ret = 0;
	cur = stk->head->next;
	while(cur != stk->tail && top < cur->data)
	{
		++ret;
		cur = cur->next;
	}
	return ret;
}

int	get_num_of_rotate(t_arr *arr, t_data target)
{
	size_t	i;
	t_data	prev;
	t_data	next;
	const t_data arr_min = get_arr_min(arr);
	const t_data arr_max = get_arr_max(arr);

	if(arr->size < 2)
		return (0);
	i = -1;
	while(++i < arr->size)
	{
		prev = arr->data[(i + arr->size - 1)% arr->size];
		next = arr->data[i];
		printf("prev_i: %lu, prev: %d , next_i: %zu, next: %d\n",(i + arr->size - 1), prev,i, next );
		if (prev == arr_max)
			prev = INT_MIN;
		if (next == arr_min)
			next = INT_MAX;
		printf("prev_i: %lu, prev: %d , next_i: %zu, next: %d\n",(i + arr->size - 1), prev,i, next );
		if (prev < target && target < next)
		{
			return (i);
		}
	}
	return (-1);
}