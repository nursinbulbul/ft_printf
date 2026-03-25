#include <stdarg.h>
#include "ft_printf.h"
#include <unistd.h>

int print_char(va_list *args)
{
    char c;
    c = va_arg(*args, int);
    write(1, &c, 1);
    return 1;
}