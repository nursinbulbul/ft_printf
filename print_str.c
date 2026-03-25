#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int print_str(va_list *args)
{
    int i;
    i = 0;

    char *str;
    str = va_arg(*args, char*);

    if (str == NULL)
    {
        
        write(1, "(null)", 6);
        return 6;
    }
    
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
    
}
