#include <unistd.h>
#include <stdbool.h>
#include "mylib.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_print_alphabet(void)
{
    char c;
    int length = 0;
    for(c = 'a'; c <= 'z'; ++c)
    {
        ++length;
    }
    char letters[length * 2];
    int index = 0;
    for(c = 'a'; c <= 'z'; ++c)
    {
        letters[index] = c;
        letters[index + 1] = ' ';
        index = index + 2;
    }
    write(1, &letters, length * 2);
    write(1, "\n", 1);
}
void ft_print_reverse_alphabet(void)
{
    char letters[26];
    char c;
    int index = 0;
    for(c = 'z'; c >= 'a'; --c)
    {
        letters[index] = c;
        ++index;
    }
    write(1, &letters, 26);
}
//Create a function that displays all digits, on a single line, by ascending order.
void ft_print_numbers(void)
{
    int i;
    char space = ' ';

    for(i = 0; i <= 9; ++i)
    {
        char c = i + '0';
        write(1, &c, 1);
        write(1, &space, 1);
    }
    write(1, "\n", 1);
}
//Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’
void ft_is_negative(int n)
{
    char c;
    if(n >= 0)
    {
        c = 'P';
    }
    else
    {
        c = 'N';
    }
    write(1, &c, 1);
    write(1, "\n", 1);
}
//Create a function that displays all different combinations of three different digits in ascending order, listed by ascending order.
void ft_print_comb(void)
{
    for(int i = 0; i <= 9; ++i)
    {
        for(int j = i + 1; j <= 9; ++j)
        {
            for(int k = j + 1; k <= 9; ++k)
            {
                char c_i = i + '0';
                char c_j = j + '0';
                char c_k = k + '0';
                char arr[3] = {c_i, c_j, c_k};
                write(1, &arr, 3);
                char space = ' ';
                write(1, &space, 1);
            }
        }
    }
    write(1, "\n", 1);
}
//Create a function that displays all different combination of two two digits numbers (XX XX) between 00 and 99, listed by ascending order.
int ft_print_comb2_subroutine(int num)
{
    char zero = '0';
    char space = ' ';
    char c_num = num % 10 + '0';
    if(num < 10)
    {
        write(1, &zero, 1);
    }
    else
    {
        char c = num / 10 + '0';
        write(1, &c, 1);
    }
    write(1, &c_num, 1);
    write(1, &space, 1);
    return 0;
}
void ft_print_comb2(void)
{
    int counter = 0;
    for(int i = 0; i <= 99; ++i)
    {
        for(int j = i + 1; j <= 99; ++j)
        {
            ft_print_comb2_subroutine(i);
            ft_print_comb2_subroutine(j);
            char space = ' ';
            write(1, &space, 1);
            ++counter;
        }
        write(1, "\n", 1);
    }
}
//Create a function that displays the number entered as a parameter. The function has to be able to display all possible values within an int type variable.
void ft_putnbr(int nb)
{
    char buff[12];
    int size = 0;
    char sign = '-';
    bool has_sign = false;

    if (nb == -2147483648) //INT_MIN
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nb < 0)
    {
        has_sign = true;
        nb = -nb;
    }
    if(nb == 0)
    {
        write(1, "0", 1);
        return;
    }
    else
    {
        while(nb > 0)
        {
            buff[size] = '0' + (nb % 10);
            nb /= 10;
            ++size;
        }
    }
    //reverse order
    char rev_buff[12];
    for(int j = 0, i = size - 1; i >= 0; ++j, --i)
    {
        rev_buff[j] = buff[i];
    }
    if(has_sign)
    {
        write(1, &sign, 1);
    }
    write(1, &rev_buff, size);
}
void print_num(int depth, int start, int max_depth, char *buff)
{
    for(int i = start; i <= 9; ++i)
    {
        buff[depth] = '0' + i;
        if(depth < max_depth)
        {
            print_num(depth + 1, i + 1, max_depth, buff);
        }
        else
        {
            write(1, buff, (max_depth + 1));
            write(1, " ", 1);
        }
    }
    if(depth == 0)
    {
        write(1, "\n", 1);
    }
}
void ft_print_combn(int n)
{
    if(n <= 0 || n > 9)
    {
        return;
    }
    char buffer[10];
    print_num(0, 0, n - 1, buffer);
}
//This function displays a string of characters on the standard output.
void ft_putstr(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
    }
    write(1, str, length_counter);
    write(1, "\n", 1);
}
void ft_put_hex_from_dec(int dec, char *hex, int size)
{
    if(size == 0)
    {
        return;
    }
    if(dec < 10)
    {
        hex[0] = '0' + dec;
    }
    int counter = 0;
    while(dec != 0)
    {
        int rem = dec % 16;
        char c = '0' + rem;
        if(rem > 9)
        {
            c = 'a' + (rem - 10);
        }
        hex[counter] = c;
        write(0, &c, 1);
        dec /= 16;
        counter++;
        if(counter >= size)
        {
            break;
        }
    }
}