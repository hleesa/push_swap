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
	if(stk->head == NULL || stk->size == 0)
		return;
	t_node *temp = stk->head->next;

	while(temp != stk->tail)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	t_stack a;

	init_stack(&a);

	for(int i=1; i<6; ++i)
	{
		add_front(&a, i);
	}
	print_stack(&a);
//	pop_back(&a);
//	print_stack(&a);
	for(int i=1; i<6; ++i)
	{
		reverse_rotate(&a);
		print_stack(&a);
	}
}
