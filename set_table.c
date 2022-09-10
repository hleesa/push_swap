/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:45:22 by salee2            #+#    #+#             */
/*   Updated: 2022/09/07 14:22:05 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_table(t_int *table, t_int val)
{
	t_int	i;

	i = -1;
	while (++i < TABLE_SIZE)
		table[i] = val;
	return ;
}

void	set_table_ra_rb(t_int *src, t_int *dst)
{
	dst[RA] = src[RA] - src[RR];
	dst[RB] = src[RB] - src[RR];
	dst[RR] = src[RR];
	dst[SUM] = dst[RA] + dst[RB] + dst[RR];
	return ;
}

void	set_table_rra_rb(t_int *src, t_int *dst)
{
	dst[RRA] = src[RRA];
	dst[RB] = src[RB];
	dst[SUM] = dst[RRA] + dst[RB];
	return ;
}

void	set_table_ra_rrb(t_int *src, t_int *dst)
{
	dst[RA] = src[RA];
	dst[RRB] = src[RRB];
	dst[SUM] = dst[RA] + dst[RRB];
	return ;
}

void	set_table_rra_rrb(t_int *src, t_int *dst)
{
	dst[RRA] = src[RRA] - src[RRR];
	dst[RRB] = src[RRB] - src[RRR];
	dst[RRR] = src[RRR];
	dst[SUM] = dst[RRA] + dst[RRB] + dst[RRR];
	return ;
}
