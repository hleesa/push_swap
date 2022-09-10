/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:18:06 by salee2            #+#    #+#             */
/*   Updated: 2022/09/10 13:56:22 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init(&a, &b, argc, &argv);
	if (is_duplicate(&a))
		return (print_error());
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
