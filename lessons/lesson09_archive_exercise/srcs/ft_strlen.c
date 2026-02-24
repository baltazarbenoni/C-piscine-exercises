#include <limits.h>

int ft_strlen(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
        //Guard against not null-terminated strings.
        if(length_counter >= INT_MAX)
        {
            return length_counter;
        }
    }
    return length_counter;
}