/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:15:30 by salee2            #+#    #+#             */
/*   Updated: 2022/08/29 15:15:31 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//
//void	sel_sort(t_stack *stk)
//{
//	t_node *base_node;
//	t_node *next_node;
//	t_node *min;
//	t_data temp;
//
//	base_node = stk->head->next;
//	while (base_node != stk->tail)
//	{
//		min = base_node;
//		next_node = base_node->next;
//		while (next_node != stk->tail)
//		{
//			if (next_node->data < min->data)
//				min = next_node;
//			next_node = next_node->next;
//		}
//		temp = base_node->data;
//		base_node->data = min->data;
//		min->data = temp;
//		base_node = base_node->next;
//	}
//	return ;
//}

void	selection_sort(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min_idx;
	t_data 	temp;

	i = 0;
	while(i < len)
	{
		min_idx = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			++j;
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		++i;
	}
	return ;
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

