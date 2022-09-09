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

#include "bonus_checker.h"

void	init_to_instr(void (*to_instr[INSTR_SIZE])(t_stack* ,t_stack*))
{
	to_instr[SA] = swap_a;
	to_instr[SB] = swap_b;
	to_instr[SS] = swap_swap;
	to_instr[PA] = push_a;
	to_instr[PB] = push_b;
	to_instr[RA] = rotate_a;
	to_instr[RB] = rotate_b;
	to_instr[RR] = rotate_rotate_bonus;
	to_instr[RRA] = reverse_rotate_a;
	to_instr[RRB] = reverse_rotate_b;
	to_instr[RRR] = reverse_rotate_reverse_rotate_bonus;
	return ;
}

void	checker(t_stack *a, t_stack *b)
{
	char *data;
	const char* instr[INSTR_SIZE] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	void (*to_instr[INSTR_SIZE])(t_stack* ,t_stack* );
	size_t i;
	t_bool is_found;

	init_to_instr(to_instr);
	while ((data = get_next_line(STDIN)) != NULL)
	{
		i = -1;
		is_found = FALSE;
		while (++i < INSTR_SIZE)
		{
			if(ft_strcmp(data, instr[i]) == 0)
			{
				to_instr[i](a, b);
				is_found = TRUE;
				break ;
			}
		}
		if (!is_found)
		{
			exit(ft_printf("Error\n"));
		}
	}
	if (is_asc_stack(a) && front(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}
