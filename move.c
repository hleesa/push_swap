/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:23:23 by salee2            #+#    #+#             */
/*   Updated: 2022/08/30 10:23:24 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *a, t_stack *b, int *sorted_arr, int arr_len)
{
	int i;
	int i_end;
	int max_b_val;

	max_b_val = sorted_arr[arr_len - (a->size / 2 + a->size % 2)];
	i =0;
	i_end = a->size;
	while(i < i_end)
	{
		if(front(a) < max_b_val)
			push_dst(a, b);
		else
			rotate_x(a);
		++i;
	}
	return ;
}

void	move_a_to_b(t_stack *a, t_stack *b, int *sorted_arr, int arr_len)
{
	while(a->size > 2)
		move_to_b(a, b, sorted_arr, arr_len);
	return;
}

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


