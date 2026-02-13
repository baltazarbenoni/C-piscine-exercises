#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include "io_utils.h"

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
/*
A function that converts the initial portion of the string pointed by str to its int representation.
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
*/
int ft_atoi(char *str)
{
    int is_pos = 1;
    int num = 0;
    int finished = 0;
    int index = 0;
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
        else if(c >= '0' && c <= '9')
        {
            if(ft_abs(num) > INT_MAX / 10)
            {
                return num;
            }
            num *= 10;
            num += c - '0';
        }
        else if(num != 0)
        {
            return num * is_pos;
        }
    }
    return num;
}
//Get character for different base systems. nbr is the number in dec, base the base-system. If base is larger than alphanumeric, behavior is undefined.
char ft_get_char_in_base(int nbr, int base)
{
    char c;
    if(base == 0 || base == 1)
    {
        return '0';
    }
    if(nbr > base)
    {
        return '0';
    }
    if(nbr < 10)
    {
        c = nbr + '0';
        return c;
    }
    else
    {
        c = 'A' + (char)(nbr - 10);
        return c;
    }
}
int ft_iterative_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    for(int i = 1; i < nb; ++i)
    {
        product *= i;
    }
    return product;
}
int ft_recursive_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    while(nb > 1)
    {
        nb = nb - 1;
        product *= nb;
    }
    return product;
}
int ft_iterative_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    long result = 1;
    for(int i = 0; i < power; ++i)
    {
        result *= nb;
    }
    int int_result = result;
    return int_result;
}
int ft_recursive_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    int result = 1;
    while(power > 0)
    {
        result *= nb;
        power -= 1;
    }
    return result;
}
int ft_fibonacci(int index)
{
    if(index < 0)
    {
        return -1;
    }
    int previous = 0;
    int element = 1;
    int temp = 0;
    while(index > 0)
    {
        temp = element;
        element += previous;
        previous = temp;
        --index;
    }
    return element;
}
int ft_sqrt(int nb)
{
    if(nb == 1)
    {
        return 1;
    }
    int root = nb / 2;
    int previous = 0;
    while(root * root != nb)
    {
        previous = root;
        //Using Newton's method.
        root = (root + nb / root) / 2;
        //If not converging --> has no retional root, exit loop.
        if(root == previous && root * root != nb)
        {
            return 0;
        }
    }
    return root;
}
int ft_is_prime(int nb)
{
    if(nb < 2)
    {
        return 0;
    }
    if(nb == 2)
    {
        return 1;
    }
    for(int i = 2; i < nb; ++i)
    {
        if(nb % i == 0)
        {
            //printf("Found divider %d, %d is not prime\n", i, nb);
            return 0;
        }
    }
    //printf("Not divider found, %d is prime\n", nb);
    return 1;
}
int ft_find_next_prime(int nb)
{
    if(ft_is_prime(nb) == 1)
    {
        //printf("nb %d is prime\n", nb);
        return nb;
    }
    while(ft_is_prime(nb) != 1)
    {
        nb += 1;
        //printf("Trying if %d is prime\n", nb);
    }
    //printf("Found! %d is prime\n", nb);
    return nb;
}
int ft_check_base(char* base, int len)
{
    //check initial conditions.
    if(base[0] == '\0' || base[1] == '\0')
    {
        return 0;
    }
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
        for(int j = 0; j < i; ++j)
        {
            if(base[j] == base[i])
            {
                return 0;
            }
        }
        ++i;
    }
    return 1;
}