/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:55:05 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 16:46:11 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	slong(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(unsigned int n)
{
	int		i;
	char	*num;

	i = slong(n);
	num = (char *)malloc(i + 1);
	if (!num)
		return (NULL);
	num[i] = '\0';
	if (n == 0)
		num[0] = '0';
	while (i > 0)
	{
		num[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

int	print_unsigned(va_list *args)
{
	unsigned int	num;
	char			*numstr;
	int				i;

	num = va_arg(*args, unsigned int);
	numstr = ft_itoa(num);
	i = 0;
	while (numstr[i])
	{
		if (write(1, &numstr[i], 1) == -1)
		{
			free(numstr);
			return (-1);
		}
		i++;
	}
	free(numstr);
	return (i);
}
