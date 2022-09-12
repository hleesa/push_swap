/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:29 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 19:09:18 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate_a(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b == NULL)
		return ;
	add_front(a, back(a));
	pop_back(a);
	return ;
}

void	reverse_rotate_b(t_stack *a, t_stack *b)
{
	if (b->size < 2 || a == NULL)
		return ;
	add_front(b, back(b));
	pop_back(b);
	return ;
}

void	reverse_rotate_reverse_rotate_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, b);
	reverse_rotate_b(a, b);
	return ;
}
