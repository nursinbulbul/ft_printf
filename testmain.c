/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:28:48 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 12:40:23 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*arr;

	arr = "nursin";
	//ft_printf("Hello %c %s %p %d %i %u %x %X %%", 'a', arr, arr, 243, -2341, 8765, 32, 32);
	//printf("\nHello %c %s %p %d %i %u %x %X %%", 'a', arr, arr, 243, -2341, 8765, 32, 32);
	
    ft_printf("Hello %%%");
	printf("\nHello %%%");
    
    return (0);
}
