/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:13:37 by salee2            #+#    #+#             */
/*   Updated: 2022/09/06 18:22:33 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	back(t_stack *stk)
{
	return (stk->tail.prev->data);
}

t_int	front(t_stack *stk)
{
	return (stk->head.next->data);
}
