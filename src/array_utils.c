#include <unistd.h>
#include <stdbool.h>
#include "mylib.h"

//Create a function which reverses a given array of integer (first goes last, etc). The arguments are a pointer to int and the number of ints in the array.
void ft_rev_int_tab(int *tab, int size)
{
    char temp;
    for(int i = 0, j = size - 1; i <= (float)(size / 2); ++i, --j)
    {
        temp = tab[j];
        tab[j] = tab[i];
        tab[i] = temp;
    }
}
//Create a function which sorts an array of integers by ascending order. The arguments are a pointer to int and the number of ints in the array.
void ft_sort_int_tab(int *buffer, int size)
{
    if(size <= 0)
    {
        return;
    }
    int tmp;
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(buffer[i] > buffer[j])
            {
                tmp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = tmp;
            }
        }
    }
}