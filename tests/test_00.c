#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "io_utils.h"

int main()
{
    ft_print_alphabet();
    ft_print_numbers();
    ft_is_negative(-5);
    ft_is_negative(5);
    //ft_print_comb();
    //ft_print_comb2();
    //power(12, 2);
    ft_putnbr(123);
    ft_putnbr(-1234);
    ft_print_combn(2);
    //ft_print_combn(4);
    //ft_print_combn(8);
    ft_print_reverse_alphabet();

    return 0;
}