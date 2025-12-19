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
    char dest[30] = "joujouuu"; 
    ft_strcpy(dest, source);
    ft_putstr(dest);
    return 0;
}