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
    return p_buffer;
}
//Exercise 05 : ft_split
/*
 Create a function that splits a string of character depending on another string of characters.
• You’ll have to use each character from the string charset as a separator.
• The function returns an array where each element of the array contains the address of a string wrapped between two separators. The last element of that array should equal to 0 to indicate the end of the array.
• There cannot be any empty strings in your array. Get your own conclusions accordingly.
• The string given as argument won’t be modifiable.
*/
//Function to check if from current position onward characters add up to the separator.
int ft_is_separator(const char *str, const char *sep, int start)
{
    int i = 0;
    while(sep[i] != '\0')
    {
        //Return 0 if this is not separator.
        if(str[i + start] != sep[i])
        {
            return 0;
        }
        ++i;
    }
    //Separator matched. Return its length.
    return i;
}
char **ft_split(char *str, char *charset)
{
    if(!str || str[0] == '\0')
    {
        return NULL;
    }
    if(!charset)
    {
        return NULL;
    }
    if(charset[0] == '\0')
    {
        char **array = malloc(2 * sizeof(char*));
        if(!array)
        {
            return NULL;
        }
        array[0] = malloc((ft_strlen(str) + 1)); 
        if(!array[0])
        {
            free(array);
            return NULL;
        }
        ft_strcpy(array[0], str);
        array[1] = NULL;
        return array;
    }
    //======================
    int i = 0;
    int string_count = 0;
    int token_start = 0;
    //======================
    //Count up the separators.
    //======================
    while(str[i] != '\0')
    {
        //On separator's first character showing up, check if this is the separator.
        if(str[i] == charset[0])
        {
            int sep_len = ft_is_separator(str, charset, i);
            if(sep_len)
            {
                //If separators not following each other, increment string count.
                if(i > token_start)
                {
                    ++string_count;
                }
                i += sep_len;
                token_start = i;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }
    //Get the last element if string does not end in separator.
    if(i > token_start)
    {
        ++string_count;
    }
    //======================
    //Allocate string array.
    char **array = malloc((string_count + 1) * sizeof(char *));
    if(!array)
    {
        return NULL;
    }
    //======================
    //Copy strings to array.
    //======================
    int strings_added = 0;
    token_start = 0;
    i = 0;
    while(str[i] != '\0')
    {
        //If match for separator's first character, check if its the separator. If it is, copy preceding string to array.
        if(str[i] == charset[0])
        {
            int sep_len = ft_is_separator(str, charset, i);
            //If this is the separator, copy the preceding token.
            if(sep_len)
            {
                if(i > token_start)
                {
                    array[strings_added] = malloc((i - token_start + 1) * sizeof(char)); 
                    if(!array[strings_added])
                    {
                        ft_free_string_array(array);
                        return NULL;
                    }
                    int k = 0;
                    while(k < i - token_start)
                    {
                        array[strings_added][k] = str[token_start + k];
                        ++k;
                    }
                    array[strings_added][k] = '\0';
                    ++strings_added;
                }
                i += sep_len;
                token_start = i;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }
    //Copy the final string if str does not end in separator.
    if(i > token_start)
    {
        array[strings_added] = malloc((i - token_start + 1) * sizeof(char)); 
        int k = 0;
        while(k < i - token_start)
        {
            array[strings_added][k] = str[token_start + k];
            ++k;
        }
        array[strings_added][k] = '\0';
        ++strings_added;
    }
    array[strings_added] = NULL;
    return array;
}
int main()
{
    int a = 84;
    int b = -68;
    int *p = ft_range(b, a);
    int size = a - b;
    ft_putnbrs(p, size);
    free(p);
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
    char split_this[] = "-XXXX-$ks--XXXX-Hella-XXXX--XXXX-I-XXXX- am $$ seecccuuriissimm-XXXX--XXXX-";
    //============================
    char **p_strings = ft_split(split_this, sep2);
    ft_print_string_array(p_strings);
    ft_free_string_array(p_strings);
    //helloo
/*
    ft_print_string_array(p_strings);
*/
/*
    char **p_strings2 = ft_split(p_buffer2, sep2);
    
    ft_print_string_array(p_strings2);
*/
    //============================
    //Free memory.
    free(p_buffer);
    free(p_buffer2);
    /*
    ft_free_string_array(p_strings);
    ft_free_string_array(p_strings2);
*/
    //===================================
    char base1[] = "0123456789";
    char base3[] = "0123456789ABCDEF";
    char nbr3[] = "249";
    char *p_buffer3 = ft_convert_base(nbr3, base1, base3);
    printf("\n");
    ft_putstr(p_buffer3);
    //============================
    free(p_buffer3);
    //============================
    char base2[] = "poneyvif";
    //char base2[] = "01234567";
    char base4[] = "01";
    char nbr1[] = "1001001";
    char nbr2[] = "19AB";
    char *p_buffer4 = ft_convert_base(nbr1, base4, base2);
    printf("number: %s base from: %s base to: %s\n", nbr1, base4, base2);
    ft_putstr(p_buffer4);
    //============================
    char *p_buffer8 = ft_convert_base(p_buffer4, base2, base4);
    printf("number: %s base from: %s base to: %s\n", p_buffer4, base2, base4);
    ft_putstr(p_buffer8);
    //============================
    free(p_buffer4);
    free(p_buffer8);
    //============================
    char *p_buffer5 = ft_convert_base(nbr2, base3, base2);
    printf("number: %s base from: %s base to: %s\n", nbr2, base3, base2);
    ft_putstr(p_buffer5);
    char *p_buffer10 = ft_convert_base(p_buffer5, base2, base3);
    printf("number: %s base from: %s base to: %s\n", p_buffer5, base2, base3);
    //============================
    ft_putstr(p_buffer10);
    free(p_buffer5);
    free(p_buffer10);
    //============================
    char *p_buffer6 = ft_convert_base(nbr2, base3, base1);
    printf("number: %s base from: %s base to: %s\n", nbr2, base3, base1);
    ft_putstr(p_buffer6);
    //============================
    free(p_buffer6);
    //============================

    //============================
    return 0;
}
