#include <unistd.h>
#include <stdbool.h>
#include "mylib.h"

void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}