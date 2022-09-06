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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init(&a, &b, argc, &argv);
	if (is_duplicate(&a))
		return (print_error());
	push_swap(&a, &b);
	return (0);
}
/*

void	print_table(int* table)
{
	printf("ra rra rb rrb   rr rrr sum\n");
	for(int i=0; i<TABLE_SIZE; ++i)
		printf("%d   ", table[i]);
	printf("\n");
}

void print_arr(t_arr *arr)
{
	printf("size: %zu\n", arr->size);
	for(size_t i=0; i< arr->size; ++i)
		printf("%d ", arr->data[i]);
	printf("\n");
}


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

 */