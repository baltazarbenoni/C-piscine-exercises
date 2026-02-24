#include "ft_stock_str.h"

int main()
{
    char *arr[5];
    arr[0] = "Hello";
    arr[1] = "World";
    arr[2] = " I ";
    arr[3] = " am ";
    arr[4] = " aliveee$$$€€€@@}]@++aliveee ";
    arr[5] = "jou";
    t_stock_str *array = ft_strs_to_tab(6, arr);
    ft_show_tab(array);
    return 0;
}