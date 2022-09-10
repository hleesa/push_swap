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

#include "checker_bonus.h"

void	swap_a(t_stack *a, t_stack *b)
{
	if (b != NULL)
		swap(a);
	return ;
}

void	swap_b(t_stack *a, t_stack *b)
{
	if (a != NULL)
		swap(b);
	return ;
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return ;
}
