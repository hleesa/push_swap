/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:37 by salee2            #+#    #+#             */
/*   Updated: 2022/08/22 16:20:40 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef int t_bool;
typedef int t_data;

typedef struct s_node
{
//	t_data			data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

t_bool	add_back(t_stack *stk, t_data data);
t_bool	add_front(t_stack *stk, t_data data);
t_node	*create_node(t_data data);
void	init_stack(t_stack *stk);
t_bool	is_empty(t_stack stk);
void	pop_back(t_stack *stk);
void	pop_front(t_stack *stk);

#endif //PUSH_SWAP_H
