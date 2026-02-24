#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "str_utils.h"
#include "io_utils.h"
//Exercise 00 : ft_strlen
//Create a function that counts and returns the number of characters in a string.
/*
       The strlen() function calculates the length of the string pointed
       to by s, excluding the terminating null byte ('\0').

       The strlen() function returns the number of bytes in the string
       pointed to by s.

*/
/*int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ++i;
    }
    return i;
}*/
//Exercise 01 : ft_putstr
//Exercise 02 : ft_putnbr
//--> Done in exercise two! --> moving on.
//=============================================//
//Exercise 03 : ft_atoi
/*
Write a function that converts the initial portion of the string pointed by str to its int representation
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change
the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
• Your function should read the string until the string stop following the rules and return
the number found until now.
• You should not take care of overflow or underflow. result can be undefined in that case.
• Here’s an example of a program that prints the atoi return value:
$>./a.out " ---+--+1234ab567"
-1234
*/
int ft_atoi(char *str)
{
    int is_pos = 1;
    int num = 0;
    int finished = 0;
    int index = 0;
    /*
    whitespaces: x >= 9 && x <= 13 || x == 32.
    plus minus: x == '+' , x == '-'
    */
    while(finished == 0)
    {
        char c = str[index];
        ++index;
        //Initial whitespace.
        if((c >= '\t' && c <= '\r') || c == ' ')
        {
            //printf("whitespace: %c\n", c);
            if(num == 0)
            {
                continue;
            }
            else
            {
                return num * is_pos;
            }
        }
        //Minus signs.
        else if(c == '-')
        {
            //printf("minus");
            if(num == 0)
            {
                is_pos *= -1;
                continue;
            }
            return num * is_pos;
        }
        //Plus signs.
        else if(c == '+')
        {
            //printf("plus");
            if(num == 0)
            {
                continue;

            }
            return num * is_pos;
        }
        //Handle numbers.
        else if(c >= '1' && c <= '9')
        {
            //printf("numbers %c", c);
            num *= 10;
            num += c - '0';
        }
        else if(num != 0)
        {
            //printf("exiting");
            return num * is_pos;
        }
    }
    return num * is_pos;
}
//Exercise 04 : ft_putnbr_base
//
/*
Create a function that displays a number in a base system in the terminal.
• This number is given in the shape of an int, and the radix in the shape of a string
of characters.
• The base-system contains all useable symbols to display that number :
◦ 0123456789 is the commonly used base system to represent decimal numbers
◦ 01 is a binary base system ;
◦ 0123456789ABCDEF an hexadecimal base system ;
◦ poneyvif is an octal base system.
• The function must handle negative numbers.
• If there’s an invalid argument, nothing should be displayed. Examples of invalid
arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - ;
*/
int ft_check_base(char* base, int len)
{
    //check initial conditions.
    if(base[0] == '\0' || base[1] == '\0')
    {
        return 0;
    }
    //create array for duplicate comparison.
    char buffer[len + 1];
    buffer[len] = '\0';
    int i = 0;
    while(base[i] != '\0')
    {
        if(base[i] == '+' || base[i] == '-')
        {
            return 0;
        }
        if((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
        {
            return 0;
        }
        int j = 0;
        while(buffer[j] != '\0')
        {
            if(base[i] == buffer[j])
            {
                return 0;
            }
            ++j;
        }
        buffer[i] = base[i];
        ++i;
    }
    return 1;
}
char ft_get_char(int nbr, int base)
{
    if(base == 0 || base == 1)
    {
        return '0';
    }
    if(nbr > base)
    {
        printf("error, digit is %d, base is %d", nbr, base);
        return '=';
    }
    if(nbr < 10)
    {
        char c = nbr + '0';
        return c;
    }
    else
    {
        char c = 'A' + (char)(nbr - 10);
        return c;
    }
}
void ft_putnbr_base(int nbr, char *base)
{
    int buffer_limit = 128;
    char buffer[buffer_limit];
    int base_len = ft_strlen(base);
    if(ft_check_base(base, base_len) < 1)
    {
        return;
    }
    if(nbr < 0)
    {
        char a = '-';
        write(1, &a, 1);
        nbr *= -1;
    }
    //get value.
    int counter = 0;
    while(nbr > 0)
    {
        int digit = (nbr % base_len);
        char c = ft_get_char(digit, base_len);
        buffer[counter] = c;
        nbr /= base_len;
        ++counter;
        //printf("\ndigit: %d, nbr: %d, base: %d, c: %c, counter: %d\n", digit, nbr, base_len, c, counter);
        if(counter >= buffer_limit)
        {
            break;
        }
    }
    //print and reverse order.
    {
        for(int x = counter - 1; x >= 0; --x)
        {
            char a = buffer[x];
            write(1, &a, 1);
        }
    }
    write(1, "\n", 1);
}
//Exercise 05 : ft_atoi_base
/*
Write a function that converts the initial portion of the string pointed by str to int representation.
• str is in a specific base given as a second parameter.
• excepted the base rule, the function should work exactly like ft_atoi.
• If there’s an invalid argument, the function should return 0. Examples of invalid arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - or whitespaces;
• Here’s how it should be prototyped :
*/
int ft_atoi_base(char *str, char *base)
{
    int number = ft_atoi(str);
    //printf("%d", number);
    ft_putnbr_base(number, base);
    return number;
}

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