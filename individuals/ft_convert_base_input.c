#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_utils.h"
#include "io_utils.h"
#include "math_utils.h"

//Exercise 04 : ft_convert_base
/*
Create a function that returns the result of the conversion of the string nbr from a base base_from to a base base_to.
• nbr, base_from, base_to may be not writable.
• nbr will follow the same rules as ft_atoi_base (from an other module). Beware of ’+’, ’-’ and whitespaces.
• The number represented by nbr must fit inside an int.
• If a base is wrong, NULL should be returned.
• The returned number must be prefix only by a single and uniq ’-’ if necessary, no
whitespaces, no ’+’.
ATOI-RULES
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
• Your function should read the string until the string stop following the rules and return the number found until now.
*/
int ft_char_index_in_string(char c, const char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == c)
        {
            return i;
        }
        ++i;
    }
    return -1;
}
typedef struct 
{
    int start;
    int length;
    int multiplier;
} num_struct;

num_struct ft_get_nbr(char *nbr, char *base)
{
    num_struct num = {.start = 0, .length = 0, .multiplier = 1};
    int i = 0;
    int started = 0;
    while(nbr[i] != '\0')
    {
        char c = nbr[i];
        if(ft_char_index_in_string(c, base) >= 0)
        {
            if(started == 0)
            {
                started = 1;
                num.start = i;
            }
            ++num.length;
        }
        else if(started != 0)
        {
            return num;
        }
        else if(c == '-')
        {
            num.multiplier *= -1;
        }
        ++i;
    }
    return num;
}

int ft_get_num_from_base(char *nbr, char *base, int base_len)
{
    num_struct num = ft_get_nbr(nbr, base);
    int i = 0;
    int pow_index = num.length;
    long sum = 0;
    while(i < num.length)
    {
        pow_index = num.length - i - 1;
        int index = num.start + i;
        int dec = ft_char_index_in_string(nbr[index], base);
        if(dec < 0)
        {
            return sum * num.multiplier;
        }
        sum += dec * ft_iterative_power(base_len, pow_index);
        ++i;
    }
    int j = sum * num.multiplier;
    return j;
}
char *ft_convert_to_base(int num, char *base, int base_len)
{
    int counter = 0;
    int length = 0;
    long num_test = num;
    int sign = 0;
    if(num == 0)
    {
        char *buffer = malloc(2);
        if (!buffer)
        {
            return NULL;
        }
        buffer[0] = base[0];
        buffer[1] = '\0';
        return buffer;
    }
    if(num_test < 0)
    {
        num_test *= -1;
        num = num_test;
        sign = 1;
    }
    while(num_test > 0)
    {
        num_test /= base_len;
        ++length;
    }
    char *buffer = malloc((length + 1 + sign) * sizeof(char));
    if(!buffer)
    {
        return NULL;
    }
    while(num > 0)
    {
        int index = (num % base_len);
        //Index is modulo of base length, cannot exceed array size.
        char c = base[index];
        buffer[counter] = c;
        num /= base_len;
        ++counter;
    }
    if(sign)
    {
        buffer[counter] = '-';
        ++counter;
    }
    ft_reverse_string(buffer);
    //Get the null.
    buffer[counter] = '\0';
    return buffer;
}
//Base rule: allow only alphanumeric base characters.
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    //Check bases are correct.
    int base_from_len = ft_strlen(base_from);
    int base_to_len = ft_strlen(base_to);

    if(ft_check_base(base_from, base_from_len) < 1 ||ft_check_base(base_to, base_to_len) < 1)
    {
        return NULL;
    }
    //Get the size of num in decimal.
    int nbr_dec = ft_get_num_from_base(nbr, base_from, base_from_len);
    //Convert to new base.
    char *p_buffer = ft_convert_to_base(nbr_dec, base_to, base_to_len);
    printf("Number %s from base %s to base %s is: %s\n", nbr, base_from, base_to, p_buffer);
    return p_buffer;
}
int main(int argc, char **argv)
{
    if(argc < 4)
    {
        char str[] = "Input the parameters: (1) number (2) base from (3) base to convert";
        write(1, &str, ft_strlen(str) * sizeof(char));
        return 0;
    }
    char *p_buffer = ft_convert_base(argv[1], argv[2], argv[3]);
    if(!p_buffer)
    {
        char str1[] = "Cannot print, pointer null";
        write(1, &str1, ft_strlen(str1) * sizeof(char));
        return 0;
    }
    //ft_putstr(p_buffer);
    return 0;
}