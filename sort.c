/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:36:38 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:08:43 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_arr *arr)
{
	size_t	i;
	size_t	j;
	size_t	min_idx;
	t_integer	temp;

	i = -1;
	while (++i < arr->size)
	{
		min_idx = i;
		j = i;
		while (++j < arr->size)
		{
			if (arr->data[j] < arr->data[min_idx])
				min_idx = j;
		}
		temp = arr->data[i];
		arr->data[i] = arr->data[min_idx];
		arr->data[min_idx] = temp;
	}
	return ;
}

void	three_sort(t_stack *stk)
{
	t_arr	arr;

	stack_to_arr(stk, &arr);
	if (arr.data[0] < arr.data[2] && arr.data[1] > arr.data[2])
	{
		swap_x(stk);
		rotate_x(stk);
	}
	if (arr.data[0] > arr.data[1] && arr.data[0] < arr.data[2] && \
	arr.data[1] < arr.data[2])
		swap_x(stk);
	if (arr.data[0] < arr.data[1] && arr.data[0] > arr.data[2] && \
	arr.data[1] > arr.data[2])
		reverse_rotate_x(stk);
	if (arr.data[0] > arr.data[2] && arr.data[1] < arr.data[2])
		rotate_x(stk);
	if (arr.data[0] > arr.data[1] && arr.data[1] > arr.data[2])
	{
		rotate_x(stk);
		swap_x(stk);
	}
	free(arr.data);
	return ;
}

void	five_sort(t_stack *a, t_stack *b)
{
	const t_integer	min = (t_integer)a->size - 3;

	if (is_asc_stack(a))
	{
		last_sort(a);
		return ;
	}
	while (a->size > 3)
	{
		if (front(a) < min)
			push_dst(a, b);
		else
			rotate_x(a);
	}
	three_sort(a);
	if (b->size > 1)
	{
		if (front(b) < back(b))
			swap_x(b);
	}
	while (!is_empty(b))
		push_dst(b, a);
	return ;
}

void	last_sort(t_stack *stk)
{
	size_t	i;
	size_t	ra;
	size_t	rra;
	t_arr	arr;

	stack_to_arr(stk, &arr);
	i = -1;
	ra = -1;
	while (++i < arr.size)
	{
		if (arr.data[i] == 0)
		{
			ra = i;
			break ;
		}
	}
	rra = arr.size - ra;
	if (rra < ra)
		reverse_rotate_repeat_x(stk, rra);
	else
		rotate_repeat_x(stk, ra);
	free(arr.data);
	return ;
}
