/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:54:53 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 16:20:55 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer_recursive(unsigned long n)
{
	int		totalcount;
	int		baseindex;
	char	*base;

	base = "0123456789abcdef";
	totalcount = 0;
	if (n >= 16)
	{
		totalcount += print_pointer_recursive(n / 16);
	}
	baseindex = n % 16;
	if (write(1, &base[baseindex], 1) == -1)
		return (-1);
	totalcount += 1;
	return (totalcount);
}

int	print_pointer(va_list *args)
{
	unsigned long	n;
	int				total;

	n = va_arg(*args, unsigned long);
	total = 0;
	if (n == '\0')
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	total += 2;
	total += print_pointer_recursive(n);
	return (total);
}
