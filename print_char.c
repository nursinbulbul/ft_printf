/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:54:29 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 16:20:48 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
