/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:27:09 by salee2            #+#    #+#             */
/*   Updated: 2022/08/20 12:27:17 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int num_of_rotate;

	while (a->size > 0)
	{
		num_of_rotate = get_num_of_rotate(front(a), b);
		if (num_of_rotate > 0)
			rotate_repeat_x(b, 'b', num_of_rotate);
		else
			reverse_rotate_repeat_x(b, 'b', -num_of_rotate);
		push_x(a, b, 'b');
		if (num_of_rotate > 0)
			reverse_rotate_repeat_x(b, 'b', num_of_rotate);
		else
			rotate_repeat_x(b, 'b', -num_of_rotate);
	}
	while (b->size > 0)
		push_x(b, a, 'a');
	return;
}