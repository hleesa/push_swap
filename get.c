/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:12:44 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:30:55 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

t_integer	get_arr_max(t_arr *arr)
{
	t_integer	ret;
	size_t	i;

	i = -1;
	ret = INT_MIN;
	while (++i < arr->size)
	{
		if (arr->data[i] > ret)
			ret = arr->data[i];
	}
	return (ret);
}

t_integer	get_arr_min(t_arr *arr)
{
	t_integer	ret;
	size_t	i;

	i = -1;
	ret = INT_MAX;
	while (++i < arr->size)
	{
		if (arr->data[i] < ret)
			ret = arr->data[i];
	}
	return (ret);
}

size_t	get_arr_min_idx(t_arr *arr)
{
	size_t			i;
	const t_integer	min = get_arr_min(arr);

	i = -1;
	while (++i < arr->size)
	{
		if (arr->data[i] == min)
			return (i);
	}
	return (-1);
}

t_integer	get_num_of_rotate(t_arr *arr, t_integer target)
{
	size_t			i;
	t_integer			front;
	t_integer			back;
	const t_integer	arr_min = get_arr_min(arr);
	const t_integer	arr_max = get_arr_max(arr);

	if (arr->size < 2)
		return (0);
	i = -1;
	while (++i < arr->size)
	{
		front = arr->data[(i + arr->size - 1) % arr->size];
		back = arr->data[i];
		if (target < arr_min && front == arr_max)
			front = INT_MIN;
		if (target > arr_max && back == arr_min)
			back = INT_MAX;
		if (front < target && target < back)
			return (i);
	}
	return (-1);
}
