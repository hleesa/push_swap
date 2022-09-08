/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:53:15 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 20:53:16 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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