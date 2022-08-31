/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:56:35 by salee2            #+#    #+#             */
/*   Updated: 2022/08/31 17:56:35 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preprocess_stack(t_stack *a)
{
	size_t	i;
	size_t	j;
	t_arr	arr;
	t_node	*cur;

	arr.data = get_sorted_arr(a, &arr.size);
	if (arr.data == NULL)
		exit(print_error());
	i = 0;
	cur = a->head->next;
	while (i < arr.size)
	{
		j = 0;
		while (j < arr.size && cur->data != arr.data[j])
			++j;
		cur->data = j;
		++i;
		cur = cur->next;
	}
	free(arr.data);
	return ;
}
