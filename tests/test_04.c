#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "io_utils.h"
#include "str_utils.h"

int main()
{
    char str[] = "   +++--+1934234.234.21jlsdf9293";
    int num = ft_atoi(str);
    ft_putnbr(num);
    ft_putnbr(-1233);
    ft_putnbr(1234);
    ft_putnbr(12345);
    ft_putnbr(-1234);
    ft_putnbr(123456);
    ft_putnbr(-123456);
    char a = 'a';
    a += (char)10;
    write(1, &a, 1);
    write(1, "\n", 1);
    char base[] = "01";
    char base1[] = "0123456789ABCDEF";
    char base2[] = "sixteen";
    ft_putnbr_base(124, base);
    ft_putnbr_base(73, base);
    ft_putnbr_base(73, base1);
    ft_putnbr_base(160, base1);
    ft_putnbr_base(256, base1);
    ft_putnbr_base(73, base2);
    ft_atoi_base(str, base1);
    return 0;
}