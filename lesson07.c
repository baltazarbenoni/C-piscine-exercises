#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_utils.h"
#include "io_utils.h"
#include "math_utils.h"

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
Write a function that will concatenate all the strings pointed by strs separated by sep.
• size is the number of strings in strs
• if size is 0, you must return an empty string that you can free().
*/
//Get the size of a string array.
size_t ft_get_string_size(char *str)
{
    size_t size = sizeof(char) * ft_strlen(str);
    return size;
}
size_t ft_get_size(char **strs, int count)
{
    if(count == 0)
    {
        return 0;
    }
    int i = 0;
    size_t full_size; 
    while(i < count)
    {
        char *str = strs[i];
        full_size += ft_get_string_size(str);
        ++i;
    }
    return full_size;
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    char empty[] = "";
    char *p_empty = malloc(sizeof(empty));
    if(size < 0)
    {
        return NULL;
    }
    if(size == 0)
    {
        return p_empty;
    }
    //Get the size. Made up of the string array size and the size of the separators (no separator in the end, size would be one less than size but for null-termination.
    size_t full_size = ft_get_size(strs, size) + ft_get_string_size(sep) * size;
    //Allocate buffer.
    char *buffer = malloc(full_size);
    //Different indexes: 1) strings to join, 2) index inside each string, 3) index inside the separator.
    int string_index = 0;
    int internal_index = 0;
    int sep_index = 0;
    //Start index to start joining string at.
    int buffer_start = 0;
    if(!buffer)
    {
        return NULL;
    }
    while(string_index < size)
    {
        //Copy string to buffer
        char *str = strs[string_index];
        while(str[internal_index] != '\0')
        {
            buffer[buffer_start + internal_index] = str[internal_index];
            ++internal_index;
        }
        buffer_start += internal_index;
        internal_index = 0;
        //Copy the separator.
        while(sep[sep_index] != '\0')
        {
            buffer[buffer_start + sep_index] = sep[sep_index];
            ++sep_index;
        }
        buffer_start += sep_index; 
        sep_index = 0;
        ++string_index;
    }
    //Null-terminate.
    buffer[buffer_start] = '\0';
    return buffer;
}
//Exercise 04 : ft_convert_base
/*
Create a function that returns the result of the conversion of the string nbr from a base base_from to a base base_to.
• nbr, base_from, base_to may be not writable.
• nbr will follow the same rules as ft_atoi_base (from an other module). Beware of ’+’, ’-’ and whitespaces.
• The number represented by nbr must fit inside an int.
• If a base is wrong, NULL should be returned.
• The returned number must be prefix only by a single and uniq ’-’ if necessary, no
whitespaces, no ’+’.
*/
int ft_char_index_in_string(char c, char *str)
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
int ft_get_num_from_base(char *nbr, char *base, int base_len)
{
    int num_len = strlen(nbr);
    int i = num_len;
    int pow_index = 0;
    int sum;
    while(i > 0)
    {
        if(nbr[i - 1] == '-')
        {
            sum *= -1;
            ++pow_index;
            --i;
            continue;
        }
        int num = ft_char_index_in_string(nbr[i - 1], base);
        if(num < 0)
        {
            return -1;
        }
        sum += num * ft_iterative_power(base_len, pow_index);
        if(sum >= INT_MAX)
        {
            return sum;
        }
        ++pow_index;
        --i;
    }
    return sum;
}
int ft_
//Base rule: allow only alphanumeric base characters.
/*char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    //Check bases are correct.
    int base_from_len = ft_strlen(base_from);
    int base_to_len = ft_strlen(base_to);
    if(ft_check_base(base_from, base_from_len) < 1 ||ft_check_base(base_to, base_to_len) < 1)
    {
        return NULL;
    }
    //Get the size of num in decimal?.
    int nbr_dec = ft_get_num_from_base(nbr, base_from, base_from_len);
    //Convert to new base.
}*/
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
/*char **ft_split(char *str, char *charset)
{
    char **p = &str;
    return p;
}*/
int main()
{
    int a = 84;
    int b = -68;
    int *p = ft_range(b, a);
    int size = a - b;
    ft_putnbrs(p, size);
    char *strs[5];
    strs[0] = "Hello";
    strs[1] = "my";
    strs[2] = "name";
    strs[3] = "is";
    strs[4] = "Nebukadnezzar";
    char sep[] = " ";
    char *p_buffer = ft_strjoin(5, strs, sep);
    ft_putstr(p_buffer);
    char sep2[] = "-XXXX-"; 
    char *p_buffer2 = ft_strjoin(5, strs, sep2);
    ft_putstr(p_buffer2);
    return 0;
}
