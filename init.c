/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:22:53 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:22:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init_stack(t_stack *stk, char name)
{
	stk->head = create_node(0);
	stk->tail = create_node(0);
	if (stk->head == NULL || stk->tail == NULL)
		return;
	stk->name = name;
	stk->size = 0;
	stk->head->prev = NULL;
	stk->head->next = stk->tail;
	stk->tail->prev = stk->head;
	stk->tail->next = NULL;
	return;
}

void	init_stack_arg(t_stack *stk, int argc, char ***argv, char name)
{
	int 	i;
	int 	args_idx;
	char	**args;
	t_bool	is_error;

	init_stack(stk, name);
	i = 1;
	while(i < argc)
	{
		args = ft_split((*argv)[i],' ');
		if(args == NULL)
			exit(print_error());
		args_idx = 0;
		while(args[args_idx])
		{
			is_error = 0;
			add_back(stk, ft_atoi(args[args_idx], &is_error));
			if (is_error)
				exit(print_error());
			++args_idx;
		}
		++i;
	}
	return ;
}
