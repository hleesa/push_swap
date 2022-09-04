/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:56:35 by salee2            #+#    #+#             */
/*   Updated: 2022/08/31 17:56:35 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_arr(t_stack *stk, t_arr *arr)
{
	size_t	i;
	t_node	*cur;

	if (stk->size == 0)
		return ;
	arr->size = stk->size;
	arr->data = ft_calloc(arr->size, sizeof(t_data));
	if (arr->data == NULL)
	{
		return ;
	}
	i = -1;
	cur = stk->head->next;
	while(++i < arr->size)
	{
		arr->data[i] = cur->data;
		cur = cur->next;
	}
	return;
}

void	selection_sort(t_arr *arr)
{
	size_t	i;
	size_t	j;
	size_t	min_idx;
	t_data 	temp;

	i = 0;
	while(i < arr->size)
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

void	preprocess_stack(t_stack *a)
{
	size_t	i;
	size_t	j;
	t_arr	arr;
	t_node	*cur;

	stack_to_arr(a, &arr);
	if (arr.data == NULL)
		exit(print_error());
	selection_sort(&arr);
	i = 0;
	cur = a->head->next;
	while (i < arr.size)
	{
		j = 0;
		while (j < arr.size && cur->data != arr.data[j])
			++j;
		cur->data = j;
		++i;
		cur = cur->next;
	}
	free(arr.data);
	return ;
}