#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "io_utils.h"

int ft_strlen(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
        //Guard against not null-terminated strings.
        if(length_counter >= 2147483647)
        {
            return length_counter;
        }
    }
    return length_counter;
}
char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = src[i];
    return dest;
}
char *ft_strcpy_paste_at_n(char *dest, char *src, int *index)
{
    int i = 0;
    int n = *index;
    char c = n + '0';
    ft_putstr("Index is: \n");
    write(1, &c, 1);
    while(src[i] != '\0')
    {
        dest[n + 1] = src[i];
        ++i;
    }
    *index = n + i;
    return dest;
}
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    _Bool source_ended = false;
    for(unsigned int i = 0; i < n; ++i)
    {
        if(source_ended == false)
        {
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '0';
        }
        if(src[i] == '\0')
        {
            source_ended = true;
        }
    }
    return dest;
}
//Create a function that returns 1 if the string given as a parameter contains only alphabetical characters, and 0 if it contains any other character.
int ft_str_is_alpha(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//Create a function that returns 1 if the string given as a parameter contains only digits, and 0 if it contains any other character.
int ft_str_is_numeric(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= '0' && c <= '9'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//Create a function that returns 1 if the string given as a parameter contains only lowercase alphabetical characters, and 0 if it contains any other character.
int ft_str_is_lowercase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'a' && c <= 'z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//Create a function that returns 1 if the string given as a parameter contains only uppercase alphabetical characters, and 0 if it contains any other character.
int ft_str_is_uppercase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'A' && c <= 'Z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//Create a function that returns 1 if the string given as a parameter contains only printable characters, and 0 if it contains any other character.
int ft_str_is_printable(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= '!' && c <= '~'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//Create a function that transforms every letter to uppercase.
char *ft_strupcase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'a' && c <= 'z'))
        {
            str[index] ^= 32;
        }
        ++index;
    }
    return str;
}
// Create a function that transforms every letter to lowercase.
char *ft_strlowcase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'A' && c <= 'Z'))
        {
            str[index] |= 0x20;
        }
        ++index;
    }
    return str;
}
int ft_is_alphanumeric(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
}
//Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase. A word is a string of alphanumeric characters.
char *ft_strcapitalize(char *str)
{
    if(str[0] == '\0')
    {
        return str;
    }
    if((str[0] >= 'a' && str[0] <= 'z'))
    {
        str[0] ^= 0x20;
    }
    int index = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'a' && c <= 'z') && !(ft_is_alphanumeric(str[index - 1])))
        {
            str[index] ^= 0x20;
        }
        else if((c >= 'A' && c <= 'Z') && ft_is_alphanumeric(str[index - 1]))
        {
            str[index] |= 0x20;
        }
        ++index;
    }
    return str;
}
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    if(size == 0)
    {
        return 0;
    }
    unsigned int i = 0;
    while(src[i] != '\0')
    {
        if(i < size)
        {
            dest[i] = src[i];
        }
        else if(i == size)
        {
            dest[i] = '\0';
        }
        ++i;
    }
    return i;
}
//==========================================
int ft_strcmp(char *s1, char *s2)
{
    if(s1[0] == '\0' && s2[0] == '\0')
    {
        return 0;
    }
    int counter1 = 0;
    int counter2 = 0;
    while(s1[counter1] != '\0')
    {
        ++counter1;
    }
    while(s2[counter2]!= '\0')
    {

        ++counter2;
        if(counter2 > counter1)
        {
            return -1;
        }
    }
    if(counter1 > counter2)
    {
        return 1;
    }
    else if(counter1 < counter2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    if(s1[0] == '\0' && s2[0] == '\0')
    {
        return 0;
    }
    int counter1 = 0;
    int counter2 = 0;
    for(unsigned int i = 0; i < n; ++i)
    {
        if(s1[i] != '\0')
        {
            ++counter1;
        }
        if(s2[i] != '\0')
        {
            ++counter2;
        }
        if(counter1 != counter2)
        {
            if(counter1 > counter2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}
char *ft_strcat(char *dest, char *src)
{
    int start = 0;
    while(dest[start] != '\0')
    {
        ++start;
    }
    int i = 0;
    while(src[i] != '\0')
    {
        dest[start + i] = src[i];
        ++i;
    }
    //Get the null
    dest[start + i] = '\0';
    return dest;
}
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int start = 0;
    while(dest[start] != '\0')
    {
        ++start;
    }
    for(unsigned int i = 0; i < nb; ++i)
    {
        if(src[i] == '\0')
        {
            //Get the null
            dest[start + i] = '\0';
            break;
        }
        dest[start + i] = src[i];
    }
    return dest;
}
//The strstr() function finds the first occurrence of the substring needle in the string haystack.  The terminating null bytes ('\0') are not compared.
char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    char* ptr;
    while(str[i] != '\0')
    {
        if(str[i] == to_find[j])
        {
            if(j == 0)
            {
                ptr = &str[i];
            }
            ++j;
        }
        else if(to_find[j] == '\0')
        {
            break;
        }
        else
        {
            ptr = NULL;
            j = 0;
        }
        ++i;
    }
    return ptr;
}
/*
The strlcpy() and strlcat() functions copy and concatenate strings respectively. They are designed to be safer, more consistent, and less error prone replacements for strncpy(3) and strncat(3). Unlike those functions, strlcpy() and strlcat() take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0 or, in the case of strlcat(), as long as there is at least one byte free in dst). Note that a byte for the NUL should be included in size. Also note that strlcpy() and strlcat() only operate on true ''C'' strings. This means that for strlcpy() src must be NUL-terminated and for strlcat() both src and dst must be NUL-terminated.

The strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

The strlcpy() and strlcat() functions return the total length of the string they tried to create. For strlcpy() that means the length of src. For strlcat() that means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.

Note, however, that if strlcat() traverses size characters without finding a NUL, the length of the string is considered to be size and the destination string will not be NUL-terminated (since there was no space for the NUL). This keeps strlcat() from running off the end of a string. In practice this should not happen (as it means that either size is incorrect or that dst is not a proper ''C'' string). The check exists to prevent potential security problems in incorrect code.
*/
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    if(size == 0)
    {
        return 0;
    }
    //Get length of dest.
    unsigned int i = 0;
    while(dest[i] != '\0')
    {
        ++i;
        //If buffer size reached, return without copying or null, terminating.
        if(i >= size)
        {
            unsigned int j = 0;
            while(src[j] != '\0')
            {
                ++j;
            }
            return i + j;
        }
    }
    //Write to buffer.
    unsigned int j = 0;
    while(src[j] != '\0' && i + j < size)
    {
        dest[i + j] = src[j];
        ++j;
    }
    //Null terminate result.
    dest[i + j] = '\0';
    return i + j;
}
//Function to reverse string. If string is not null-terminated, behaviour is undefined.
char *ft_reverse_string(char *str)
{
    int length = ft_strlen(str);
    int i = 0;
    int j = length - 1;
    while(i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i;
        --j;
    }
    return str;
}
void ft_free_string_array(char **str)
{
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        ++i;
    }
    free(str);
}
void ft_freen_string_array(char **str, int size)
{
    int i = 0;
    while(i < size)
    {
        free(str[i]);
        ++i;
    }
    free(str);
}
char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *p_src = (char *)malloc(len);
    if (p_src == NULL)
    {
        return NULL;
    }
    ft_strcpy(p_src, src);
    return p_src;
}
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