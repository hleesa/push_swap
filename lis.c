/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:38:57 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:24:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_memo_from(t_arr *arr, t_arr *memo, t_arr *from)
{
	size_t	i;

	memo->size = arr->size;
	memo->data = ft_calloc(memo->size, sizeof(t_int));
	from->size = arr->size;
	from->data = ft_calloc(from->size, sizeof(t_int));
	if (memo->data == NULL || from->data == NULL)
		exit(print_error());
	i = -1;
	while (++i < from->size)
		from->data[i] = -1;
	return ;
}

void	get_lis_memo_from_offset(t_arr *arr, t_arr *memo, t_arr *from, \
size_t ofs)
{
	size_t	i;
	size_t	j;
	size_t	i_ofs;
	size_t	j_ofs;

	init_memo_from(arr, memo, from);
	i = -1;
	while (++i < arr->size)
	{
		i_ofs = (i + ofs) % arr->size;
		memo->data[i_ofs] = 1;
		j = -1;
		while (++j < i)
		{
			j_ofs = (j + ofs) % arr->size;
			if (arr->data[j_ofs] < arr->data[i_ofs] && \
			memo->data[j_ofs] + 1 > memo->data[i_ofs])
			{
				memo->data[i_ofs] = memo->data[j_ofs] + 1;
				from->data[arr->data[i_ofs]] = arr->data[j_ofs];
			}
		}
	}
	return ;
}

size_t	get_lis_len(t_arr *memo)
{
	size_t	i;
	t_int	len;

	len = 0;
	i = -1;
	while (++i < memo->size)
	{
		if (memo->data[i] > len)
			len = memo->data[i];
	}
	return (len);
}

void	update_lis(t_arr *memo, t_arr *from, t_arr *c_memo, t_arr *c_from)
{
	size_t			i;
	const size_t	lis_len = get_lis_len(memo);
	const size_t	c_lis_len = get_lis_len(c_memo);

	if (c_lis_len > lis_len)
	{
		i = -1;
		while (++i < memo->size)
		{
			memo->data[i] = c_memo->data[i];
			from->data[i] = c_from->data[i];
		}
	}
	return ;
}

void	get_lis_memo_from(t_stack *stk, t_arr *memo, t_arr *from)
{
	t_arr	arr;
	t_arr	c_memo;
	t_arr	c_from;
	size_t	offset;

	stack_to_arr(stk, &arr);
	init_memo_from(&arr, memo, from);
	offset = -1;
	while (++offset < stk->size)
	{
		get_lis_memo_from_offset(&arr, &c_memo, &c_from, offset);
		update_lis(memo, from, &c_memo, &c_from);
		free(c_memo.data);
		free(c_from.data);
	}
	free(arr.data);
	return ;
}
