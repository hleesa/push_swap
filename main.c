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
	t_lis 	is_lis;

	if(argc == 1)
		return (0);
	init(&a, &b, argc, &argv);
	if (is_duplicate(&a))	// need edit
		return (print_error());
	stack_to_is_lis(&a, &is_lis);
//	print_stack_a_b(&a, &b);
	push_swap(&a, &b);
//	print_stack_a_b(&a, &b);

	return (0);
}
