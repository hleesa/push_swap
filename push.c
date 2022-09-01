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