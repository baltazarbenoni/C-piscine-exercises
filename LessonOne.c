#include <unistd.h>
#include <stdio.h>

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
}

void ft_print_numbers(void)
{
    char digits[20];
    int i;
    int index = 0;
    for(i = 0; i <= 9; ++i)
    {
        digits[index]  = (char)i;
        digits[index+1] = ' ';
        index = index + 2;
    }
    int size = sizeof(digits) / sizeof(char);
    printf("%s", digits);
    printf("\n");
    printf("%p", &digits);
    //write(1, &digits, size);
}

int main()
{
    ft_print_alphabet();
    printf("\n");
    ft_print_numbers();
    return 0;
}