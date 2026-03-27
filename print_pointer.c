#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int print_pointer_recursive(unsigned long n)
{
    int totalcount;
    totalcount = 0;
    int baseindex;
    char base[] = {"0123456789abcdef"};

    if (n >= 16)
    {
        totalcount += print_pointer_recursive(n / 16);
    }
    baseindex = n % 16;
    write(1, &base[baseindex], 1);
    totalcount += 1;
    
    return totalcount; 
}

int print_pointer(va_list *args)
{
    void *p;
    p = va_arg(*args, void *);

    unsigned long n;
    n = (unsigned long)p;

    int total;
    total = 0;

    if (p == NULL)
    {
        write(1, "0x0", 3);
        return 3;
    }
    write(1, "0x", 2);
    total += 2;
    total += print_pointer_recursive(n);
    
    return total;
}
