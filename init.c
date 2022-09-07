/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:22:53 by salee2            #+#    #+#             */
/*   Updated: 2022/09/07 14:31:06 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stk, char name)
{
	stk->head = create_node(-1);
	stk->tail = create_node(-1);
	stk->name = name;
	stk->size = 0;
	stk->head->prev = NULL;
	stk->head->next = stk->tail;
	stk->tail->prev = stk->head;
	stk->tail->next = NULL;
	return ;
}

void	init_stack_arg(t_stack *stk, int argc, char ***argv, char name)
{
	ssize_t	i;
	ssize_t	args_idx;
	t_bool	is_error;
	char	**args;

	init_stack(stk, name);
	i = 0;
	while (++i < argc)
	{
		args = ft_split((*argv)[i], ' ');
		if (args == NULL || args[0] == 0)
			exit(ft_printf("Error\n"));
		args_idx = -1;
		while (args[++args_idx])
		{
			is_error = 0;
			if(args[args_idx][0] == '\0')
				exit(ft_printf("Error\n"));
			add_back(stk, ft_atoi(args[args_idx], &is_error));
			if (is_error)
				exit(ft_printf("Error\n"));
		}
	}
	return ;
}

void	init(t_stack *a, t_stack *b, int argc, char ***argv)
{
	init_stack(b, 'b');
	init_stack_arg(a, argc, argv, 'a');
	preprocess_stack(a);
	return ;
}

void	init_set_type_table(void (*set_type_table[4])(t_data*, t_data*))
{
	set_type_table[0] = set_table_ra_rb;
	set_type_table[1] = set_table_rra_rb;
	set_type_table[2] = set_table_ra_rrb;
	set_type_table[3] = set_table_rra_rrb;
	return ;
}
