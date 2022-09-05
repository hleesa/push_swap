/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:03:17 by salee2            #+#    #+#             */
/*   Updated: 2022/08/29 15:03:18 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putendl_fd("Error", 1);
	return (-1);
}


void	print_table(int* table)
{
	printf("ra rra rb rrb   rr rrr sum\n");
	for(int i=0; i<TABLE_SIZE; ++i)
		printf("%d   ", table[i]);
	printf("\n");
}
