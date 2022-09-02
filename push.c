/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:45:53 by salee2            #+#    #+#             */
/*   Updated: 2022/08/25 14:45:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if (src->size == 0)
		return;
	add_front(dst, front(src));
	pop_front(src);
}

void	push_dst(t_stack *src, t_stack *dst)
{
	push(src, dst);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(dst->name, 1);
	ft_putchar_fd('\n', 1);
	return;
}

void	push_b_half(t_stack *a, t_stack *b)
{
	size_t			i;
	const size_t	i_end = a->size;
	const t_data	mid_val = i_end	/ 2;

	i = -1;
	while(++i < i_end)
	{
		if(front(a) < mid_val)
		{
			push_dst(a, b);
		}
		else
		{
			rotate_x(a);
		}
	}
}
