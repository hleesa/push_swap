/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:29 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 20:53:30 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	reverse_rotate_a(t_stack *a, t_stack *b)
{
	t_int	temp;

	if (a->size < 2 || b == NULL)
		return ;
	temp = a->tail.prev->data;
	pop_back(a);
	add_front(a, temp);
	return ;
}

void	reverse_rotate_b(t_stack *a, t_stack *b)
{
	t_int	temp;

	if (b->size < 2 || a == NULL)
		return ;
	temp = b->tail.prev->data;
	pop_back(b);
	add_front(b, temp);
	return ;
}

void	reverse_rotate_reverse_rotate_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, b);
	reverse_rotate_b(a, b);
	return ;
}
