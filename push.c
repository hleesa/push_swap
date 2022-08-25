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
	t_data	data;

	if (dst->size == 0)
		return;
	data = front(dst);
	pop_front(dst);
	add_front(src, data);
}