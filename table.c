/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:38:28 by salee2            #+#    #+#             */
/*   Updated: 2022/09/07 14:20:10 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rotate_table(t_int *table, t_arr *arr, t_arr *brr, size_t i)
{
	table[RA] = get_num_of_rotate(arr, brr->data[i]);
	table[RRA] = arr->size - table[RA];
	table[RB] = i;
	table[RRB] = brr->size - table[RB];
	table[RR] = min(table[RA], table[RB]);
	table[RRR] = min(table[RRA], table[RRB]);
	return ;
}

t_int	get_min_type(t_int *table, t_int *min_table)
{
	t_int	min_type;

	min_type = -1;
	if (table[RA] + table[RB] - table[RR] < min_table[SUM])
	{
		min_type = RA_RB;
		min_table[SUM] = table[RA] + table[RB] - table[RR];
	}
	if (table[RRA] + table[RB] < min_table[SUM])
	{
		min_type = RRA_RB;
		min_table[SUM] = table[RRA] + table[RB];
	}
	if (table[RA] + table[RRB] < min_table[SUM])
	{
		min_type = RA_RRB;
		min_table[SUM] = table[RA] + table[RRB];
	}
	if (table[RRA] + table[RRB] - table[RRR] < min_table[SUM])
	{
		min_type = RRA_RRB;
		min_table[SUM] = table[RRA] + table[RRB] - table[RRR];
	}
	return (min_type);
}

void	get_min_table(t_int *table, t_int *min_table, \
void (*set_type_table[4])(t_int*, t_int*))
{
	const t_int	min_type = get_min_type(table, min_table);

	if (min_type == -1)
		return ;
	set_table(min_table, 0);
	set_type_table[min_type](table, min_table);
	return ;
}

void	get_min_rotate_table(t_stack *a, t_stack *b, t_int *min_table, \
void (*set_type_table[4])(t_int*, t_int*))
{
	size_t	i;
	size_t	i_end;
	t_arr	arr;
	t_arr	brr;
	t_int	rotate_table[TABLE_SIZE];

	stack_to_arr(a, &arr);
	stack_to_arr(b, &brr);
	set_table(rotate_table, 0);
	set_table(min_table, INT_MAX);
	i = -1;
	i_end = b->size;
	while (++i < i_end)
	{
		get_rotate_table(rotate_table, &arr, &brr, i);
		get_min_table(rotate_table, min_table, set_type_table);
	}
	free(arr.data);
	free(brr.data);
	return ;
}

void	init_set_type_table(void (*set_type_table[4])(t_int*, t_int*))
{
	set_type_table[0] = set_table_ra_rb;
	set_type_table[1] = set_table_rra_rb;
	set_type_table[2] = set_table_ra_rrb;
	set_type_table[3] = set_table_rra_rrb;
	return ;
}
