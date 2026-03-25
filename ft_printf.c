#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int handle_format(char specifier, va_list *args)
{

    if (specifier == 'c')
    {
        return print_char(args);
    } else if (specifier == 's')
    {
        return print_str(args);
    } else if (specifier == 'd' || specifier == 'i')
    {
        return print_int(args);
    } else if (specifier == 'u')
    {
        return print_unsigned(args);
    }
    
    
    
    return 0;
    
}

int ft_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);

    int i;
    int total;
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

int main()
{
    ft_printf("Hello %u", 4632123);
    printf("\nHello %u", 4632123);
    return 0;
}