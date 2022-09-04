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
	size_t i;
	const size_t end = a->size;

	i = -1;
	while (++i < end)
	{
		if (is_lis->arr.data[front(a)] == 0)
			push_dst(a, b);
		else
			rotate_x(a);
	}
}
/*
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

void	push_a_temp(t_stack *a, t_stack *b)
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

void	r_rotate_push_a(t_stack *a, t_stack *b)
{
	while (!is_empty(b))
	{
		reverse_rotate_x(b);
		push_dst(b, a);
	}
}

void	push_b_bottom_of_a(t_stack *a, t_stack *b, size_t num)
{
	size_t i;

	i = -1;
	while(++i < num)
	{
		reverse_rotate_x(a);
		push_dst(a, b);
	}
}

t_bool	is_over_two_thirds(t_data num, t_data total)
{
	return (num * 5 >= 3 * total);
}

*/

void	rotate_stack(t_stack *a, t_stack *b, int *table)
{
	rotate_repeat_x(a, table[RA]);
	reverse_rotate_repeat_x(a, table[RRA]);
	rotate_repeat_x(b, table[RB]);
	reverse_rotate_repeat_x(b, table[RRB]);
	rotate_rotate_repeat_x(a, b, table[RR]);
	reverse_rotate_rotate_repeat_x(a, b, table[RRR]);
	return;
}

void	update_min_table(int* table, int *min_table)
{
	int i;

	i = -1;
	while(++i < TABLE_SIZE)
	{
		min_table[i] = table[i];
		if(min_table[i] == INT_MAX)
			min_table[i] = 0;
	}
	if(min_table[RR] > 0)
	{
		min_table[RA] -= min_table[RR];
		min_table[RB] -= min_table[RR];
		min_table[SUM] = min_table[RA] + min_table[RB] + min_table[RR];
	}
	if(min_table[RRR] > 0)
	{
		min_table[RRA] -= min_table[RRR];
		min_table[RRB] -= min_table[RRR];
		min_table[SUM] = min_table[RRA] + min_table[RRB] + min_table[RRR];
	}
	return;
}

void	get_min_table(int *table, int *min_table)
{
	if(table[RA] + table[RB] - table[RR] * 2 < min_table[SUM])
		update_min_table(table, min_table);
	if(table[RRA] + table[RB] < min_table[SUM])
		update_min_table(table, min_table);
	if(table[RA] + table[RRB] < min_table[SUM])
		update_min_table(table, min_table);
	if(table[RRA] + table[RRB] - table[RRR] * 2 < min_table[SUM])
		update_min_table(table, min_table);
	return ;
}

void	init_min_table(int* min_table)
{
	int i;

	i = -1;
	while(++i < TABLE_SIZE)
		min_table[i] = INT_MAX;
	return;
}

void print_arr(t_arr *arr)
{
	printf("size: %zu\n", arr->size);
	for(size_t i=0; i< arr->size; ++i)
		printf("%d ", arr->data[i]);
	printf("\n");
}
void get_min_rotate_table(t_stack *a, t_stack *b, int* min_table)
{
	size_t	i;
	t_arr arr;
	t_arr brr;
	int rotate_table[TABLE_SIZE];

	stack_to_arr(a, &arr);
	stack_to_arr(b, &brr);
	i = -1;
	while(++i < b->size)
	{
		rotate_table[RA] = get_num_of_rotate(&arr, brr.data[i]);
		rotate_table[RRA] = arr.size - rotate_table[RA];
		rotate_table[RB] = i;
		rotate_table[RRB] = brr.size - rotate_table[RB];
		rotate_table[RR] = min(rotate_table[RA], rotate_table[RB]);
		rotate_table[RRR] = min(rotate_table[RRA], rotate_table[RRB]);
		get_min_table(rotate_table, min_table);
	}
	return ;
}

void	tripartition_stack(t_stack *a, t_stack *b)
{
	

}

void	push_swap(t_stack *a, t_stack *b)
{
	int  min_table[TABLE_SIZE];
//	const size_t end = a->size;
	printf("start\n");
	print_stack_a_b(a,b);
//	while(a->size < end)

	printf("1\n");
	get_min_rotate_table(a, b, min_table);
	rotate_stack(a,b,min_table);
	push_dst(b, a);
	print_stack_a_b(a,b);

	printf("2\n");
	get_min_rotate_table(a, b, min_table);
	rotate_stack(a,b,min_table);
	push_dst(b, a);
	print_stack_a_b(a,b);

//	printf("================\n");
//	print_stack(a);
//	print_stack(b);
//	printf("================\n");
}

