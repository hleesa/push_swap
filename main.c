/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:32 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:20:33 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void print_stack(t_stack *stk)
{
	if (stk->head == NULL || stk->size == 0)
	{
		printf("\n");
		return;
	}
	t_node *temp = stk->head->next;

	while(temp != stk->tail)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void print_stack_a_b(t_stack *a, t_stack *b)
{
	printf("a :");
	print_stack(a);
	printf("b :");
	print_stack(b);
}

int main(int argc, char** argv)
{
	t_stack a;
	t_stack b;

	init(&a, &b, argc, &argv);
	if (is_duplicate(&a))
		return (print_error());
	print_stack_a_b(&a, &b);
/*
	push_b(&a, &b, &arr, 16);
	print_stack_a_b(&a, &b);
	push_b(&a, &b, &arr, 8);
	print_stack_a_b(&a, &b);
	push_b(&a, &b, &arr, 4);
	print_stack_a_b(&a, &b);
	push_a(&a, &b, &arr, 16);
	print_stack_a_b(&a, &b);
*/

/*
	sort_a_half(&a, &b);
	print_stack_a_b(&a, &b);
	move_b_to_a(&a, &b, sorted_arr, arr_len);
	sort_b_half(&a, &b);
	print_stack_a_b(&a, &b);
	while (!is_empty(&b))
		push_dst(&b, &a);
	print_stack_a_b(&a, &b);
*/

// free stack
	return (0);
}
