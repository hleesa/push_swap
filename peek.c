/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:13:37 by salee2            #+#    #+#             */
/*   Updated: 2022/08/26 18:13:38 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	back(t_stack *stk)
{
	return stk->tail->prev->data;
}

t_data	front(t_stack *stk)
{
	return stk->head->next->data;
}

t_data	front_second(t_stack *stk)
{
	return stk->head->next->next->data;
}