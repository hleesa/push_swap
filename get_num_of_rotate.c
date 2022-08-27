/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:12:44 by salee2            #+#    #+#             */
/*   Updated: 2022/08/27 14:12:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_of_rotate(t_data top, t_stack *stk)
{
	int		ret;
	t_node	*cur;

	ret = 0;
	cur = stk->head->next;
	while(cur != stk->tail && top < cur->data)
	{
		++ret;
		cur = cur->next;
	}
	return ret;
}

#include <stdio.h>

int	get_num_of_rotate(t_data top, t_stack *stk)
{
	int	ret;
	int	rotate_num;
	int	reverse_rotate_num;
	
	rotate_num = num_of_rotate(top, stk);
	reverse_rotate_num = stk->size - rotate_num;
	if(rotate_num <= reverse_rotate_num)
		ret = rotate_num;
	else
		ret = -reverse_rotate_num;
//	printf("grn: %d\n", rotate_num);
//	printf("grrn: %d\n", reverse_rotate_num);
	return ret;
}
