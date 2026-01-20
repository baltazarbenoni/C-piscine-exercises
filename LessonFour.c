#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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
    for(int i = 0; i < n; ++i)
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
    for(int i = 0; i < nb; ++i)
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
*/
char *ft_strstr(char *str, char *to_find)
{

}

int main()
{
    char str2[] = "hello all my friends!";
    char str1[] = "hello all m";
    printf("%d\n", ft_strcmp(str1, str2));
    printf("%d\n", ft_strncmp(str1, str2, 4));
    printf("%d\n", ft_strncmp(str1, str2, 20));
    
    return 0;
}


