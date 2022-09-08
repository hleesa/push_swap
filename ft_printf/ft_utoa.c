/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:34:02 by salee2            #+#    #+#             */
/*   Updated: 2022/08/06 14:35:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_u_size(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		++size;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (size);
}

void	to_u_string(unsigned int n, char *str, size_t idx)
{
	if (n < 10)
	{
		str[idx] = n + '0';
		return ;
	}
	to_u_string(n / 10, str, idx - 1);
	str[idx] = n % 10 + '0';
	return ;
}

char	*ft_utoa(unsigned int n)
{
	char			*ret;
	const size_t	size = get_u_size(n);

	ret = (char *) malloc(size + 1);
	if (ret == 0)
		return (0);
	to_u_string(n, ret, size - 1);
	ret[size] = '\0';
	return (ret);
}
