#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
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
int *ft_range(int min, int max)
{

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
