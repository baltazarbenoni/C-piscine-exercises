#include <unistd.h>
#include <stdbool.h>

int ft_abs(int num)
{
    if(num < 0)
    {
        return -num;
    }
    else
    {
        return num;
    }
}
void ft_print_ints(int *arr, int size)
{
    if(size == 0)
    {
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        ft_putnbr(arr[i]);
    }
}
//function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod.
void ft_div_mod(int a, int b, int *div, int *mod)
{
    *mod = a % b;
    *div = a / b;
}
//This function divides parameters a by b. The result of this division is stored in the int pointed by a. The remainder of the division is stored in the int pointed by b.
void ft_ultimate_div_mod(int *a, int *b)
{
    int tmp = *a;
    *a = *a / *b;
    *b = tmp % *b;
}