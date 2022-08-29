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

	push_dst(a, b);
	push_dst(a, b);
	if (front(b) < back(b))
		swap_x(b);
	while (a->size > 0)
	{
//		printf("a :");
//		print_stack(a);
//		printf("b :");
//		print_stack(b);

		if (front(a) < back(b))
		{
			push_dst(a, b);
			rotate_repeat_x(b, 1);
			continue;
		}
		if (front(a) > front(b))
		{
			push_dst(a, b);
			continue ;
		}
		num_of_rotate = get_num_of_rotate(front(a), b);

//		printf("n_o_r: %d\n", num_of_rotate);

		if (num_of_rotate > 0)
			rotate_repeat_x(b, num_of_rotate);
		else
			reverse_rotate_repeat_x(b,	-num_of_rotate);
		push_dst(a, b);
		if (num_of_rotate > 0)
			reverse_rotate_repeat_x(b, num_of_rotate);
		else
			rotate_repeat_x(b,-num_of_rotate + 1);
	}
//	printf("a :");
//	print_stack(a);
//	printf("b :");
//	print_stack(b);
	while (b->size > 0)
		push_dst(b, a);
	return;
}