/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:15 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 19:09:05 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	return ;
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	return ;
}
