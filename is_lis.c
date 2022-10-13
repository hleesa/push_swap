/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:06:52 by salee2            #+#    #+#             */
/*   Updated: 2022/10/12 20:06:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_is_lis(t_arr *arr, t_arr *memo, t_arr *from, t_arr *is_lis)
{
	size_t	i;
	t_int	last_idx;
	const t_int lis_len = get_lis_len(memo);

	i = 0;
	while (++i < memo->size)
	{
		if (memo->data[i] == lis_len)
			last_idx = i;
	}
	while (from->data[last_idx] != -1)
	{
		is_lis->data[arr->data[last_idx]] = 1;
		last_idx = from->data[last_idx];
	}
	is_lis->data[arr->data[last_idx]] = 1;
	return ;
}

void	stack_to_is_lis(t_stack *stk, t_lis *is_lis)
{
	size_t	i;
	t_arr	arr;
	t_arr	memo;
	t_arr	from;

	stack_to_arr(stk, &arr);
	get_lis_memo_from(stk, &memo, &from);
	is_lis->size = 0;
	i = -1;
	while (++i < memo.size)
	{
		if (memo.data[i] > (t_int)is_lis->size)
			is_lis->size = memo.data[i];
	}
	is_lis->arr.size = stk->size;
	is_lis->arr.data = ft_calloc(is_lis->arr.size, sizeof(t_int));
	if (is_lis->arr.data == NULL)
		exit(print_error());
	get_is_lis(&arr, &memo, &from, &is_lis->arr);
	free(arr.data);
	free(memo.data);
	free(from.data);
	return ;
}
