/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:44 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 19:08:27 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_to_instr(void (*to_instr[INSTR_SIZE])(t_stack*, t_stack*))
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

void	get_instruction(t_stack *a, t_stack *b, const char *instr[INSTR_SIZE], \
void (*to_instr[INSTR_SIZE])(t_stack*, t_stack*))
{
	char	*input;
	size_t	i;
	t_bool	is_instr;

	while (TRUE)
	{
		i = -1;
		input = get_next_line(STDIN);
		if (input == NULL)
			return ;
		is_instr = FALSE;
		while (++i < INSTR_SIZE)
		{
			if (ft_strcmp(input, instr[i]) == 0)
			{
				to_instr[i](a, b);
				is_instr = TRUE;
				break ;
			}
		}
		free(input);
		if (!is_instr)
			exit(print_error());
	}
}

void	checker(t_stack *a, t_stack *b)
{
	const char	*instr[INSTR_SIZE] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr"};
	void		(*to_instr[INSTR_SIZE])(t_stack*, t_stack*);

	init_to_instr(to_instr);
	get_instruction(a, b, instr, to_instr);
	if (is_asc_stack(a) && front(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}
