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

void	push_b_not_lis(t_stack *a, t_stack *b, t_lis *is_lis)
{
	size_t	i;
	const size_t end = a->size;

	i = -1;
	while(++i < end)
	{
		if(is_lis->arr.data[front(a)] == 0)
			push_dst(a, b);
		else
			rotate_x(a);
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	size_t	i;
	const size_t end = a->size + b->size;
	int num_of_rot;

	i = -1;
	while(++i < end)
	{
//		printf("================\n");
//		printf("front(a): %d\n", front(a));
//		printf("i: %zu\n", i);
//		print_stack(a);
//		print_stack(b);

		if(front(a) == (t_data)i)
		{
			rotate_x(a);
			continue;
		}
		num_of_rot = get_num_of_rotate(i, b);
		if (num_of_rot > 0)
			rotate_repeat_x(b, num_of_rot);
		else
			reverse_rotate_repeat_x(b, -num_of_rot);
		push_dst(b, a);
		if(front(a) <= (t_data)i)
			rotate_x(a);

//		printf("front(a): %d\n", front(a));
//		printf("i: %zu\n", i);
//		print_stack(a);
//		print_stack(b);
//		printf("================\n");
	}
}

void	push_swap(t_stack *a, t_stack *b, t_lis *is_lis)
{
	push_b_not_lis(a, b, is_lis);
//	printf("================\n");
//	print_stack(a);
//	print_stack(b);
//	printf("================\n");
	push_a(a, b);
}