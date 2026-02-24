#include <unistd.h>

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