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

void	base_two_sort(t_stack *src, t_stack *dst)
{
	while(dst->size < 2 && src != dst && !is_empty(src))
//	while(src != dst && !is_empty(src))
//		push_dst(src, dst);
	if (dst->name == 'a' && front(dst) > dst->head->next->next->data)
		swap_x(dst);
	if (dst->name == 'b' && front(dst) < dst->head->next->next->data)
		swap_x(dst);
}