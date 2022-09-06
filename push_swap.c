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
	t_lis			is_lis;
	int				min_table[TABLE_SIZE];
	const size_t	end = a->size;

	stack_to_is_lis(a, &is_lis);
	push_b_not_lis(a, b, &is_lis);
	while (a->size < end)
	{
		set_table(min_table, INT_MAX);
		get_min_rotate_table(a, b, min_table);
		rotate_stack(a, b, min_table);
		push_dst(b, a);
	}
	last_sort(a);
	return ;
}
