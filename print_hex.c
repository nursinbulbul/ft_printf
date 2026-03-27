#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int print_hex_recursive(unsigned int n, char *base)
{
    int totalcount;
    totalcount = 0;
    int baseindex;

    if (n >= 16)
    {
        totalcount += print_hex_recursive(n / 16, base);
    }
    baseindex = n % 16;
    write(1, &base[baseindex], 1);
    totalcount += 1;
    
    return totalcount; 
}

int print_hex(va_list *args, char basetype)
{
    int total;
    total = 0;

    unsigned int num;
    num = va_arg(*args, unsigned int);

    char basex[] = {"0123456789abcdef"};
    char baseX[] = {"0123456789ABCDEF"};

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    if (basetype == 'x')
    {
        total = print_hex_recursive(num, basex);
    } else if (basetype == 'X')
    {
        total = print_hex_recursive(num, baseX);
    }
    
    return total;
}
