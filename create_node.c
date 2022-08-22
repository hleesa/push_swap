/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:49 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:35:50 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(t_data data)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (ret == 0)
		return (NULL);
	ret->data = data;
	return (ret);
}