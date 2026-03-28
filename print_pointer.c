/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:54:53 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 12:24:45 by nbulbul          ###   ########.fr       */
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
	write(1, &base[baseindex], 1);
	totalcount += 1;
	return (totalcount);
}

int	print_pointer(va_list *args)
{
	void			*p;
	unsigned long	n;
	int				total;

	p = va_arg(*args, void *);
	n = (unsigned long)p;
	total = 0;
	if (p == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	total += 2;
	total += print_pointer_recursive(n);
	return (total);
}
