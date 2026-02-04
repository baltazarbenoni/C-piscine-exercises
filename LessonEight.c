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
int *ft_range(int min, int max)
{
    if(max <= min)
    {
        ft_putstr("Max value is smaller than min!\n");
        return NULL;
    }
    long int len = max - min;
    if(len > INT_MAX)
    {
        return NULL;
    }
    int *p_arr = malloc(len * sizeof(int));
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
    if(max <= min)
    {
        *range = NULL;
        return 0;
    }
    long int len = max - min;
    if(len > INT_MAX)
    {
        *range = NULL;
        return -1;
    }
    int *p_arr = malloc(len * sizeof(int));
    if (p_arr == NULL)
    {
        *range = NULL;
        return -1;
    }
    for(int i = 0; i < len; ++i)
    {
        p_arr[i] = min + i;
    }
    *range = p_arr;
    return len;
}
//Exercice 03 : ft_strjoin
/*
Write a function that will concatenate all the strings pointed by strs separated by
sep.
• size is the number of strings in strs
• if size is 0, you must return an empty string that you can free().

*/
char *ft_strjoin(int size, char **strs, char *sep)
{
    return sep;
}
//Exercise 04 : ft_convert_base
/*
Create a function that returns the result of the conversion of the string nbr from a
base base_from to a base base_to.
• nbr, base_from, base_to may be not writable.
• nbr will follow the same rules as ft_atoi_base (from an other module). Beware of
’+’, ’-’ and whitespaces.
• The number represented by nbr must fit inside an int.
• If a base is wrong, NULL should be returned.
• The returned number must be prefix only by a single and uniq ’-’ if necessary, no
whitespaces, no ’+’.
*/
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    return nbr;
}
//Exercise 05 : ft_split
/*
 Create a function that splits a string of character depending on another string of
characters.
• You’ll have to use each character from the string charset as a separator.
• The function returns an array where each element of the array contains the address
of a string wrapped between two separators. The last element of that array should
equal to 0 to indicate the end of the array.
• There cannot be any empty strings in your array. Get your own conclusions accordingly.
• The string given as argument won’t be modifiable.
*/
char **ft_split(char *str, char *charset)
{
    char **p = &str;
    return p;
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
