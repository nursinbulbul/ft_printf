#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>

static int	sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	slong(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (sign(n))
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*num;

	nb = n;
	i = slong(nb);
	num = (char *)malloc(i + 1);
	if (!num)
		return (NULL);
	num[i] = '\0';
	if (nb == 0)
		num[0] = '0';
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	while (i > sign((long)n))
	{
		num[i - 1] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (num);
}

int print_int(va_list *args)
{
    int num;
    num = va_arg(*args, int);

    char *strnum;
    strnum = ft_itoa(num);

    int i;
    i = 0;

    while (strnum[i])
    {
        write(1, &strnum[i], 1);
        i++;
    }
    
    free(strnum);
    return i;

}