/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:15:30 by salee2            #+#    #+#             */
/*   Updated: 2022/08/29 15:15:31 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min_idx;
	t_data 	temp;

	i = 0;
	while(i < len)
	{
		min_idx = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			++j;
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		++i;
	}
	return ;
}
