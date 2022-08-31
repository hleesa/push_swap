/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:47:24 by salee2            #+#    #+#             */
/*   Updated: 2022/08/31 13:47:27 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack *a, t_stack *b, int *sorted_arr, int arr_len)
{
	int i;
	int i_end;
	int max_b_val;

	if(arr_len ==0) return;
	max_b_val = sorted_arr[b->size / 2 + b->size % 2];
	i =0;
	i_end = b->size;
	while(i < i_end)
	{
		if(front(b) >= max_b_val)
			push_dst(b, a);
		else
			rotate_x(b);
		++i;
	}
	return ;
}

void	move_b_to_a(t_stack *a, t_stack *b, int *sorted_arr, int arr_len)
{
	if(arr_len ==0) return;
	while(b->size > 2)
		move_to_a(a, b, sorted_arr, arr_len);
	return;
}

void	sort_b(t_stack *a, t_stack *b)
{
	if(front(b) < front_second(b))
	{
		if (front(a) > front_second(a))
			ss(a, b);
		else
			swap_x(b);
	}
}

void	sort_b_half(t_stack *a, t_stack *b)
{
	size_t b_szie;

	b_szie = a->size + b->size;
	b_szie = b_szie / 2;
	while(b->size < b_szie)
	{
		sort_b(a, b);
		push_dst(a, b);
	}
}




