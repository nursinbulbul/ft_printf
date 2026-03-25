#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int ft_printf(const char *format, ...);
int print_char(va_list *args);
int print_str(va_list *args);
int print_int(va_list *args);


#endif 