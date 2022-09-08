/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:09 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 20:53:10 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	swap(a);
	return ;
}

void	swap_b(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	swap(b);
	return ;
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return ;
}


