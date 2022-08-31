/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:46:19 by salee2            #+#    #+#             */
/*   Updated: 2022/08/31 13:46:20 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b, t_arr *arr, size_t range)
{
	size_t	i;
	t_data mid_val = arr->data[b->size + range /2];

	printf("mid val: %d\n", mid_val);
	i = 0;
	while (i < range)
	{
		if(front(a) < mid_val)
			push_dst(a, b);
		else
			rotate_x(a);
		++i;
	}
}

void	push_a(t_stack *a, t_stack *b, t_arr *arr, size_t range)
{
	size_t	i;
	t_data mid_val = arr->data[arr->size - (b->size + range /2)];

	i = 0;
	while (i < range)
	{
		if(front(a) >= mid_val)
			push_dst(b, a);
		else
			rotate_x(b);
		++i;
	}
}



/*
void	push_b_half(t_stack *a, t_stack *b, t_arr *arr)
{
	int i;
	int i_end;
	int max_b_val;

	max_b_val = arr->data[arr->size - (a->size / 2 + a->size % 2)];
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

void	push_a_half(t_stack *a, t_stack *b, int *sorted_arr, int arr_len)
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


void	sort_a(t_stack *a, t_stack *b)
{
	if(front(a) > front_second(a))
	{
		if (front(b) < front_second(b))
			ss(a, b);
		else
			swap_x(a);
	}
}

void	sort_a_half(t_stack *a, t_stack *b)
{
	size_t a_size;

	a_size = a->size + b->size;
	a_size = a_size / 2 + a_size % 2;
	while(a->size < a_size)
	{
		sort_a(a, b);
		push_dst(b, a);
	}
}

*/