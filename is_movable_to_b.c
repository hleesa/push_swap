/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:07:55 by salee2            #+#    #+#             */
/*   Updated: 2022/08/26 18:07:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_movable_to_b(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return TRUE;
	if (front(a) > front(b))
		return TRUE;
}
