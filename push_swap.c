/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:27:09 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:17:30 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_lis	is_lis;
	t_data	min_table[TABLE_SIZE];
	void	(*set_type_table[4])(t_data*, t_data*);

	if (a->size == 3)
	{
		three_sort(a);
		return ;
	}
	init_set_type_table(set_type_table);
	stack_to_is_lis(a, &is_lis);
	push_b_not_lis(a, b, &is_lis);
	while (!is_empty(b))
	{
		get_min_rotate_table(a, b, min_table, set_type_table);
		rotate_stack(a, b, min_table);
		push_dst(b, a);
	}
	last_sort(a);
	free(is_lis.arr.data);
	return ;
}
