/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:38:57 by salee2            #+#    #+#             */
/*   Updated: 2022/09/01 14:38:58 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_memo_from(t_stack *stk, t_arr *arr, t_arr *memo, t_arr *from)
{
	size_t	i;

	stack_to_arr(stk, arr);
	memo->size = arr->size;
	memo->data = ft_calloc(memo->size, sizeof(t_data));
	from->size = arr->size;
	from->data = ft_calloc(from->size, sizeof(t_data));
	if (arr->data == NULL || memo->data == NULL || from->data == NULL)
		exit(print_error());
	i = -1;
	while(++i < from->size)
		from->data[i] = -1;
	return ;
}

void	get_lis(t_stack *stk, t_arr *memo, t_arr *from)
{
	size_t	i;
	size_t	j;
	t_arr	arr;

	stack_to_arr(stk, &arr);
	init_memo_from(stk, &arr, memo, from);
	i = -1;
	while(++i < arr.size)
	{
		memo->data[i] = 1;
		j = -1;
		while(++j < i)
		{
			if(arr.data[j] < arr.data[i] && memo->data[j] + 1 > memo->data[i])
			{
				memo->data[i] = memo->data[j] + 1;
				from->data[arr.data[i]] = arr.data[j];
			}
		}
	}
	free(arr.data);
	return ;
}

void	get_is_lis(t_arr *arr, t_arr *memo, t_arr *from, t_arr *is_lis)
{
	size_t i;
	t_data max_len;
	t_data end_val;

	max_len = 1;
	end_val = 0;
	i = 0;
	while(++i < memo->size)
	{
		if(memo->data[i] > max_len)
		{
			max_len = memo->data[i];
			end_val = arr->data[i];
		}
	}
	while(from->data[end_val] != -1)
	{
		is_lis->data[end_val] = 1;
		end_val = from->data[end_val];
	}
	is_lis->data[end_val] = 1;
	return ;
}

void	stack_to_is_lis(t_stack *stk, t_lis *is_lis)
{
	size_t	i;
	t_arr	arr;
	t_arr	memo;
	t_arr	from;

	stack_to_arr(stk, &arr);
	get_lis(stk, &memo, &from);
	is_lis->size = 0;
	i = -1;
	while(++i < memo.size)
	{
		if (memo.data[i] > (t_data)is_lis->size)
			is_lis->size = memo.data[i];
	}
	is_lis->arr.size = stk->size;
	is_lis->arr.data = ft_calloc(is_lis->arr.size, sizeof(t_data));
	if (is_lis->arr.data == NULL)
		exit(print_error());
	get_is_lis(&arr, &memo, &from, &is_lis->arr);
	return ;
}