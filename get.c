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

t_data	get_arr_max(t_arr *arr)
{
	t_data	ret;
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

t_data	get_arr_min(t_arr *arr)
{
	t_data	ret;
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

t_data	get_num_of_rotate(t_arr *arr, t_data target)
{
	size_t			i;
	t_data			front;
	t_data			back;
	const t_data	arr_min = get_arr_min(arr);
	const t_data	arr_max = get_arr_max(arr);

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
