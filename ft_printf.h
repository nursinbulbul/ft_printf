/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbulbul <nbulbul@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:55 by nbulbul           #+#    #+#             */
/*   Updated: 2026/03/28 12:00:46 by nbulbul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(va_list *args);
int	print_str(va_list *args);
int	print_int(va_list *args);
int	print_unsigned(va_list *args);
int	print_hex(va_list *args, char basetype);
int	print_pointer(va_list *args);

#endif