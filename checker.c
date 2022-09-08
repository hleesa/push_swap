/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:44 by salee2            #+#    #+#             */
/*   Updated: 2022/09/08 11:19:45 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_to_instr(void (*to_instr[INSTR_SIZE])(t_stack* ,t_stack*))
{
	to_instr[sa] = swap_a;
	to_instr[sb] = swap_b;
	to_instr[ss] = swap_swap;
	to_instr[pa] = push_a;
	to_instr[pb] = push_b;
	to_instr[ra] = rotate_a;
	to_instr[rb] = rotate_b;
	to_instr[rr] = rotate_rotate;
	to_instr[rra] = reverse_rotate_a;
	to_instr[rra] = reverse_rotate_b;
	to_instr[rrr] = reverse_rotate_reverse_rotate;
	return ;
}

void	checker(t_stack *a, t_stack *b)
{
	int data_len;
	char buff[BUFFER_SIZE];
	char *data;
	const char* instr[INSTR_SIZE] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	void (*to_instr[INSTR_SIZE])(t_stack* ,t_stack*);
	size_t i;
	t_bool is_found;

	init_to_instr(to_instr);
	while ((data_len = read(STDIN, buff, BUFFER_SIZE)) > 0)
	{
		data = get_next_line(STDIN);
		i = -1;
		is_found = FALSE;
		while (++i < INSTR_SIZE)
		{
			if(ft_strncmp(data, instr[i], data_len - 1) == 0)
			{
				to_instr[i](a, b);
				is_found = TRUE;
				break ;
			}
		}
		if (!is_found)
			exit(ft_printf("Error\n"));
	}
	if (is_asc_stack(a) && front(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}
