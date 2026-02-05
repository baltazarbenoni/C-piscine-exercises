#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "io_utils.h"

int main()
{
    int div = 0;
    int mod = 0;
    ft_div_mod(10, 3, &div, &mod);
    printf("result: %d, remainder: %d", div, mod);
    printf("\n");
    ft_div_mod(97, 17, &div, &mod);
    printf("result: %d, remainder: %d", div, mod);
    printf("\n");
    int a = 194;
    int b = 17;
    ft_ultimate_div_mod(&a, &b);
    printf("result: %d, remainder: %d", a, b);
    char str[] = "kakka";
    char str2[] = "29321jaaaksjda";
    ft_putstr(str);
    ft_putstr(str2);
    char str3[] = "kakkakakkakakkakakka";
    int count = ft_strlen(str3);
    printf("\nCount is : %d\n", count);
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft_rev_int_tab(ar, 10);

    return 0;
}