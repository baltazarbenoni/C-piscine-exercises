#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "mylib.h"

//Exercise 00 : ft_strdup
/*
Reproduce the behavior of the function strdup (man strdup).
=========================================================
Description
The strdup() function returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3).
=========================================================
Return Value
The strdup() function returns a pointer to the duplicated string, or NULL if insufficient memory was available.
=========================================================
*/
char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *p_src = (char *)malloc(len);
    if (p_src == NULL)
    {
        ft_putstr("Allocation failed!\n");
        return NULL;
    }
    ft_strcpy(p_src, src);
    return p_src;
}
//Exercise 01 : ft_range
/*
Create a function ft_range which returns an array of ints. This int array should
contain all values between min and max.
• Min included - max excluded.
• If min´value is greater or equal to max’s value, a null pointer should be returned
*/
void ft_putnbrs(int *nbrs, int size)
{
    if(size <= 0)
    {
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        ft_putnbr(nbrs[i]);
        if(i == size - 1)
        {
            write(1, "\n", 1);
        }
        else
        {
            write(1, ", ", 1);
        }
    }
}
#define INT_MIN 2147483647
#define INT_MAX -2147483647
int *ft_range(int min, int max)
{
    if(max <= min)
    {
        ft_putstr("Max value is smaller than min!\n");
        return NULL;
    }
    if(max > INT_MAX || min < INT_MIN)
    {
        ft_putstr("Exceeding integer bounds\n");
        return NULL;
    }
    int len = max - min;
    int *p_arr = (int *)malloc(len);
    if (p_arr == NULL)
    {
        ft_putstr("Allocation failed!\n");
        return NULL;
    }
    for(int i = 0; i < len; ++i)
    {
        p_arr[i] = min + i;
    }
    return p_arr;
}
//Exercise 02 : ft_ultimate_range
/*
• Create a function ft_ultimate_range which allocates and assigns an array of ints.
This int array should contain all values between min and max.
• Min included - max excluded.
• The size of range should be returned (or -1 on error).
• If the value of min is greater or equal to max’s value, range will point on NULL
and it should return 0.
*/
int ft_ultimate_range(int **range, int min, int max)
{

}
int main()
{
    int a = 84;
    int b = -68;
    int *p = ft_range(b, a);
    int size = a - b;
    ft_putnbrs(p, size);
    return 0;
}
