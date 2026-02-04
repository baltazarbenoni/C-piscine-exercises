#include <unistd.h>
#include <stdbool.h>
#include "mylib.h"

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
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    _Bool source_ended = false;
    for(int i = 0; i < n; ++i)
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
    int flag = 1;
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
    int flag = 1;
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
    int flag = 1;
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
    int flag = 1;
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
    int flag = 1;
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
    if(size = 0)
    {
        return 0;
    }
    int i = 0;
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