/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:37 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 12:42:43 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (print_char(args));
	else if (specifier == 's')
		return (print_str(args));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(args));
	else if (specifier == 'u')
		return (print_unsigned(args));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hex(args, specifier));
	else if (specifier == 'p')
		return (print_pointer(args));
	else if (specifier == '%')
	{
		write(1, '%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total += handle_format(format[i], &args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			total += 1;
			i++;
		}
	}
	va_end(args);
	return (total);
}
