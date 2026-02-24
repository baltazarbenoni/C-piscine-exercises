#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "io_utils.h"

//Exercise 00 : ft_strcmp
//Reproduce the behavior of the function strcmp (man strcmp).
/*
strcmp() returns an integer indicating the result of the
       comparison, as follows:
       •  0, if the s1 and s2 are equal;
       •  a negative value if s1 is less than s2;
       •  a positive value if s1 is greater than s2.
*/
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
//Exercise 01 : ft_strncmp
//Reproduce the behavior of the function strncmp (man strncmp).
/*
    The strncmp() function is similar (to strcmp), except it compares only the first (at most) n bytes of s1 and s2.
*/
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
//Exercise 02 : ft_strcat
//Reproduce the behavior of the function strcat (man strcat).
/*
The strcat() function shall append a copy of the string pointed to
by s2 (including the terminating NUL character) to the end of the
string pointed to by s1.  The initial byte of s2 overwrites the
NUL character at the end of s1.  If copying takes place between
objects that overlap, the behavior is undefined.
*/
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
//Exercise 03 : ft_strncat
/*
Reproduce the behavior of the function strncat (man strncat).

       This function appends at most size non-null bytes from the array
       pointed to by src, followed by a null character, to the end of the
       string pointed to by dst.  dst must point to a string contained in
       a buffer that is large enough, that is, the buffer size must be at
       least strlen(dst) + strnlen(src, ssize) + 1.

*/
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
//Exercise 04 : ft_strstr
//Reproduce the behavior of the function strstr (man strstr).
/*
The strstr() function finds the first occurrence of the substring
       needle in the string haystack.  The terminating null bytes ('\0')
       are not compared.

       The strcasestr() function is like strstr(), but ignores the case
       of both arguments.

       These functions return a pointer to the beginning of the located
       substring, or NULL if the substring is not found.

       If needle is the empty string, the return value is always haystack
       itself.
*/
char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    char* ptr;
    while(str[i] != '\0')
    {
        //printf("i is %d, and j is %d\n", i, j);
        //printf("i (%d) char is %c, and j (%d) char is %c\n", i, str[i], j, to_find[j]);
        if(str[i] == to_find[j])
        {
            if(j == 0)
            {
                //printf("pointer inside: %p\n", &str[i]);
                ptr = &str[i];
            }
            ++j;
        }
        else if(to_find[j] == '\0')
        {
            //printf("Exiting loop\n");
            break;
        }
        else
        {
            //printf("Restarting\n");
            ptr = NULL;
            j = 0;
        }
        ++i;
    }
    return ptr;
}
//Exercise 05 : ft_strlcat
//Reproduce the behavior of the function strlcat (man strlcat).
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
int main()
{
    char str2[] = "hello all my friends!";
    char str1[] = "hello all m";
    //char hello1[128];
    char hello1[] = "hello1";
    char hey[] = "hey all my hello";
    char hella[] = "hello";
    char hello2[] = "hello2 hello3 hello4";
    char hello3[] = "hellooo1234";
    char wroom2[] = "car say wroom quand il va vite wroom";
    char wroom3[] = "wroo";
    char wroom4[] = "car say wroom quand il va vite wroom";
    wroom4[15] = '\0';
    ft_putnbr(ft_strcmp(str1, str2));
    write(1, "\n", 1);
    ft_putnbr(ft_strncmp(str1, str2, 4));
    write(1, "\n", 1);
    ft_putnbr(ft_strncmp(str1, str2, 20));
    write(1, "\n", 1);
    ft_strcat(hello1, hello2);
    ft_strncat(hello2, hello3, 6);
    ft_putstr(hello1);
    write(1, "\n", 1);
    ft_putstr(hello2);
    write(1, "\n", 1);
    write(1, "\n", 1);
    write(1, "\n", 1);
    write(1, "\n", 1);
    char* p = ft_strstr(hey, hella);
    char msg[] = "found string at";
    ft_putstr(msg);
    //write(1, p2, 1);
    write(1, "\n", 1);
    write(1, p, 1);
    write(1, "\n", 1);
    char *a = ft_strstr(wroom2, wroom3);
    write(1, a, 1);
    ft_strlcat(wroom4, hella, 20);
    write(1, "\n", 1);
    ft_putstr(wroom4);
    return 0;
}