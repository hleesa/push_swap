/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:45:53 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:19:16 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if (is_empty(src))
		return ;
	add_front(dst, front(src));
	pop_front(src);
	return ;
}

void	push_dst(t_stack *src, t_stack *dst)
{
	push(src, dst);
	ft_printf("p%c\n", dst->name);
	return ;
}

void	push_b_not_lis(t_stack *a, t_stack *b, t_lis *is_lis)
{
	const t_bool	is_rot = is_rotate(a, is_lis);

	if (is_lis->size == a->size)
		return ;
	while (!is_asc_stack(a))
	{
		if (is_lis->arr.data[front(a)] == 0)
			push_dst(a, b);
		else
		{
			if (is_rot)
				rotate_x(a);
			else
				reverse_rotate_x(a);
		}
	}
	return ;
}
