/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:38:28 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 17:38:29 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	get_min_type(int *table, int *min_table)
{
	int min_type;

	min_type = -1;
	if(table[RA] + table[RB] - table[RR] < min_table[SUM])
	{
		min_type = RA_RB;
		min_table[SUM] = table[RA] + table[RB] - table[RR];
	}
	if(table[RRA] + table[RB] < min_table[SUM])
	{
		min_type = RRA_RB;
		min_table[SUM] = table[RRA] + table[RB];
	}
	if(table[RA] + table[RRB] < min_table[SUM])
	{
		min_type = RA_RRB;
		min_table[SUM] = table[RA] + table[RRB] ;
	}
	if(table[RRA] + table[RRB] - table[RRR] < min_table[SUM])
	{
		min_type = RRA_RRB;
		min_table[SUM] = table[RRA] + table[RRB] - table[RRR];
	}
	return (min_type);
}

void	set_table(int* table, int val)
{
	int i;

	i = -1;
	while(++i < TABLE_SIZE)
		table[i] = val;
	return;
}

void	get_min_table(int *table, int *min_table)
{
	const int min_type = get_min_type(table, min_table);

	if(min_type == -1) return;
	if(min_type == RA_RB)
	{
		set_table(min_table, 0);
		min_table[RA] = table[RA] - table[RR];
		min_table[RB] = table[RB] - table[RR];
		min_table[RR] = table[RR];
		min_table[SUM] = min_table[RA] + min_table[RB] + min_table[RR];
	}
	else if(min_type == RRA_RB)
	{
		set_table(min_table, 0);
		min_table[RRA] = table[RRA];
		min_table[RB] = table[RB];
		min_table[SUM] = min_table[RRA] + min_table[RB];
	}
	else if(min_type == RA_RRB)
	{
		set_table(min_table, 0);
		min_table[RA] = table[RA];
		min_table[RRB] = table[RRB];
		min_table[SUM] = min_table[RA] + min_table[RRB];
	}
	else if(min_type == RRA_RRB)
	{
		set_table(min_table, 0);
		min_table[RRA] = table[RRA] - table[RRR];
		min_table[RRB] = table[RRB] - table[RRR];
		min_table[RRR] = table[RRR];
		min_table[SUM] = min_table[RRA] + min_table[RRB] + min_table[RRR];
	}
}


void get_min_rotate_table(t_stack *a, t_stack *b, int* min_table)
{
	size_t	i;
	size_t 	i_end;
	t_arr arr;
	t_arr brr;
	int rotate_table[TABLE_SIZE];

	set_table(rotate_table, 0);
	stack_to_arr(a, &arr);
	stack_to_arr(b, &brr);
	i = -1;
	i_end = b->size;
	while(++i < i_end)
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
*/