#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//Exercise 00:
//Reproduce the behavior of the function strcpy (man strcpy).
/*
strcpy: Copy string
Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).

To avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source (including the terminating null character), and should not overlap in memory with source.
*/
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
//=======================================================
//Exercise 01:
//Reproduce the behavior of the function strncpy (man strncpy).
/*
===========================================
strncpy
Copy characters from string
Copies the first num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.

No null-character is implicitly appended at the end of destination if source is longer than num. Thus, in this case, destination shall not be considered a null terminated C string (reading it as such would overflow). Destination and source shall not overlap (see memmove for a safer alternative when overlapping).
*/
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    bool source_ended = false;
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
//=======================================================
//Exercise 02:
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
//=======================================================
//Exercise 03:
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
//=======================================================
//Exercise 04:
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
//=======================================================
//Exercise 05:
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
//=======================================================
//Exercise 06:
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
//=======================================================
//Exercise 07:
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
//=======================================================
//Exercise 08:
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
//=======================================================
//Exercise 09:
//Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase. A word is a string of alphanumeric characters.
int is_alphanumeric(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
}
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
        if((c >= 'a' && c <= 'z') && !(is_alphanumeric(str[index - 1])))
        {
            str[index] ^= 0x20;
        }
        else if((c >= 'A' && c <= 'Z') && is_alphanumeric(str[index - 1]))
        {
            str[index] |= 0x20;
        }
        ++index;
    }
    return str;
}
//=======================================================
//Exercise 10:
//Reproduce the behavior of the function strlcpy (man strlcpy).

/*

*/
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
//=======================================================
//Exercise 11:
/*
Create a function that displays a string of characters onscreen. If this string contains characters that aren’t printable, they’ll have to be displayed in the shape of hexadecimals (lowercase), preceeded by a "backslash".
 For example :
    Coucou\ntu vas bien ?
• The function should display :
    Coucou\0atu vas bien ?
*/
void ft_putstr_non_printable(char *str)
{

}
//=======================================================



void ft_putstr(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
    }
    write(1, str, length_counter);
    write(1, "\n", 1);
}
int main()
{
    char source[] = "hei minun nimeni on jaakko";
    char dest[40] = "joujouuu"; 
    char test[] = "lksajdflksjaflkjp";
    char test2[] = "lksf9034l";
    char test3[] = "";
    char test4[] = "120934345943";
    ft_strncpy(dest, source, 30);
    ft_putstr(dest);
    printf("%d\n", ft_str_is_alpha(test));
    printf("%d\n", ft_str_is_alpha(test2));
    printf("%d\n", ft_str_is_alpha(dest));
    printf("%d\n", ft_str_is_alpha(test3));
    printf("%d\n", ft_str_is_numeric(test3));
    printf("%d\n", ft_str_is_numeric(test4));
    printf("%d\n", ft_str_is_numeric(test));
    ft_putstr(ft_strupcase(test));
    ft_putstr(ft_strlowcase(test));
    ft_putstr(ft_strcapitalize(test));
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_putstr(ft_strcapitalize(str));
    return 0;
}