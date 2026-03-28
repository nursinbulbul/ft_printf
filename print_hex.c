/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:54:37 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 16:20:50 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_recursive(unsigned int n, char *base)
{
	int	totalcount;
	int	baseindex;

	totalcount = 0;
	if (n >= 16)
	{
		totalcount += print_hex_recursive(n / 16, base);
	}
	baseindex = n % 16;
	if (write(1, &base[baseindex], 1) == -1)
		return (-1);
	totalcount += 1;
	return (totalcount);
}

int	print_hex(va_list *args, char basetype)
{
	int				total;
	unsigned int	num;
	char			*base_x;
	char			*base_upperx;

	base_x = "0123456789abcdef";
	base_upperx = "0123456789ABCDEF";
	total = 0;
	num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (basetype == 'x')
	{
		total = print_hex_recursive(num, base_x);
	}
	else if (basetype == 'X')
	{
		total = print_hex_recursive(num, base_upperx);
	}
	return (total);
}
