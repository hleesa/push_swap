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
	t_data	temp;

	i = 0;
	while (i < arr->size)
	{
		min_idx = i;
		j = i + 1;
		while (j < arr->size)
		{
			if (arr->data[j] < arr->data[min_idx])
				min_idx = j;
			++j;
		}
		temp = arr->data[i];
		arr->data[i] = arr->data[min_idx];
		arr->data[min_idx] = temp;
		++i;
	}
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
	i = -1;
	if (rra < ra)
		reverse_rotate_repeat_x(stk, rra);
	else
		rotate_repeat_x(stk, ra);
	return ;
}
