/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:23 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 20:53:24 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	rotate(a);
	return ;
}

void	rotate_b(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	rotate(b);
	return ;
}

void	rotate_rotate_bonus(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
	return ;
}


