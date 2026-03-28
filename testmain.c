/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:28:48 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 17:35:51 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char	*arr;

	// arr = "nursin";
	//ft_printf("Hello %c %s %p %d %i %u %x %X %%", 'a', arr, arr, 243, -2341, 8765, 32, 32);
	//printf("\nHello %c %s %p %d %i %u %x %X %%", 'a', arr, arr, 243, -2341, 8765, 32, 32);
	
    // ft_printf("uzunluk: %d\n", ft_printf("Hello %c\n", 'a'));
	// ft_printf("uzunluk: %d\n", printf("Hello %c\n", 'a'));
    // printf("uzunluk: %d\n", ft_printf("Hello %c\n", 'a'));
	// printf("uzunluk: %d\n", printf("Hello %c\n", 'a'));

    // ft_printf("Hello %f %c", 1.23, 'a');
    // printf("\nHello %f %c", 1.23, 'a');
    
    // ft_printf("unsigned %u" , -1);
    // printf("\nunsigned %u" , -1);

    // ft_printf("int %i %i %i %i" , 2147483647, 2147483648, -2147483648, -2147483649);
    // printf("\nint %i %i %i %i" , 2147483647, 2147483648, -2147483648, -2147483649);

    ft_printf("%%%");
    printf("\n%%%");

    return (0);
}
