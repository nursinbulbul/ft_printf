#include <stdarg.h>
#include <unistd.h>
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

int print_unsigned(va_list *args)
{
    unsigned int num;
    num = va_arg(*args, unsigned int);

    char *numstr;
    numstr = ft_itoa(num);

    int i;
    i = 0;

    while (numstr[i])
    {
        write(1, &numstr[i], 1);
        i++;
    }
    
    free(numstr);
    return i;
}
