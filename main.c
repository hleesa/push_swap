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

void	print_arr(int* arr, int len)
{
	for(int i=0; i<len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	t_stack a;
	t_stack b;
	int 	*sorted_arr;
	size_t 	arr_len;

	init_stack(&b,'b');
	init_stack_arg(&a, argc, &argv, 'a');
	sorted_arr = get_sorted_arr(&a, &arr_len);
	if (sorted_arr == NULL)
		return (print_error());
	if (is_duplicate(sorted_arr, arr_len))
		exit(print_error());


	push_dst(&a, &b);
	push_dst(&a, &b);
	printf("a :");
	print_stack(&a);
	printf("b :");
	print_stack(&b);
	printf("=====sort =====\n");
//	base_two_sort(&a, &b);

//	push_swap(&a, &b);
	printf("a :");
	print_stack(&a);
	printf("b :");
	print_stack(&b);
	return (0);
}
