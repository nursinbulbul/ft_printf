/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:37 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 17:43:14 by nbulbul          ###   ########.fr       */
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
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	specifier_check(char c, va_list *args)
{
	int	n;

	n = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		n = handle_format(c, args);
		if (n == -1)
		{
			return (-1);
		}
		return (n);
	}
	else
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		len;

	va_start(args, format);
	i = 0;
	total = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			total = specifier_check(format[++i], &args);
			if (total == -1)
				return (-1);
			len += total;
			i++;
		}
		else if (write(1, &format[i++], 1) == -1)
			return (-1);
		len += 1;
	}
	va_end(args);
	return (len);
}
