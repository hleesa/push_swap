/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:56:35 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:06:25 by salee2           ###   ########.fr       */
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
	arr->data = ft_calloc(arr->size, sizeof(t_int));
	if (arr->data == NULL)
		exit(print_error());
	i = -1;
	cur = stk->head.next;
	while (++i < arr->size)
	{
		arr->data[i] = cur->data;
		cur = cur->next;
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
	selection_sort(&arr);
	i = -1;
	cur = a->head.next;
	while (++i < arr.size)
	{
		j = 0;
		while (j < arr.size && cur->data != arr.data[j])
			++j;
		cur->data = j;
		cur = cur->next;
	}
	free(arr.data);
	return ;
}

void	rotate_stack(t_stack *a, t_stack *b, t_int *table)
{
	rotate_repeat_x(a, table[RA]);
	reverse_rotate_repeat_x(a, table[RRA]);
	rotate_repeat_x(b, table[RB]);
	reverse_rotate_repeat_x(b, table[RRB]);
	rotate_rotate_repeat_x(a, b, table[RR]);
	reverse_rotate_rotate_repeat_x(a, b, table[RRR]);
	return ;
}
