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
	stk->head.data = -1;
	stk->tail.data = -1;
	stk->name = name;
	stk->size = 0;
	stk->head.prev = NULL;
	stk->head.next = &stk->tail;
	stk->tail.prev = &stk->head;
	stk->tail.next = NULL;
	return ;
}

void	init_stack_arg(t_stack *stk, int argc, char ***argv)
{
	ssize_t	i;
	ssize_t	args_i;
	t_bool	is_error;
	char	**args;

	i = 0;
	while (++i < argc)
	{
		args = ft_split((*argv)[i], ' ');
		if (args == NULL || *args == NULL)
			exit(ft_printf("Error\n"));
		args_i = -1;
		while (args[++args_i])
		{
			is_error = 0;
			if (args[args_i][0] == '\0')
				exit(ft_printf("Error\n"));
			add_back(stk, ft_atoi(args[args_i], &is_error));
			if (is_error)
				exit(ft_printf("Error\n"));
			free(args[args_i]);
		}
		free(args[args_i]);
		free(args);
	}
}

void	init(t_stack *a, t_stack *b, int argc, char ***argv)
{
	init_stack(b, 'b');
	init_stack(a, 'a');
	init_stack_arg(a, argc, argv);
	preprocess_stack(a);
	return ;
}
