#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

void ft_is_negative(int n)
{
    char c;
    int* ptr = &n;
    if(n >= 0 || ptr == NULL)
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

int power(int num, int power)
{
    int result = 1;
    if(power < 1)
    {
        return result;
    }
    else
    {
        for(int i = 1; i <= power; ++i)
        {
            result = result * num;
        }
    }
    printf("%d", result);
    printf("\n");
}
int get_abs(int num)
{
    if(num < 0)
    {
        return num * -1;
    }
    else
    {
        return num;
    }
}

void ft_putnbr(int nb)
{
    char buff[12];
    int index = 0;
    int reverse_start = 0;

    if (nb == INT_MIN)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nb < 0)
    {
        buff[index] = '-';
        ++index;
        reverse_start = 1;
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
            buff[index] = '0' + (nb % 10);
            nb /= 10;
            ++index;
            printf("%d", index);
            printf("\n");
        }
    }
    //reverse order.
    for(int j = reverse_start, i = index - 1; j <= (float)(index / 2); ++j, --i)
    {
        char temp = buff[i];
        buff[i] = buff[j];
        buff[j] = temp;
    }
    write(1, &buff, index);
    write(1, "\n", 1);
}
/*
Create a function that displays all different combinations of n numbers by ascending
order.
• n will be so that : 0 < n < 10
void ft_print_combn(int n);

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
*/ 
void print_zero(int n)
{
    char zero = '0';
    if(n < 10)
    {
        write(1, &zero, 1);
    }
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
    write(1, "\n", 1);
    ft_print_combn(4);
    ft_print_combn(8);
    return 0;
}