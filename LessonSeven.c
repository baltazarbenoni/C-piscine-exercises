#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "mylib.h"
//Exercise 00 : ft_print_program_name
//Create a program that displays its own name followed by a new line.
void ft_print_program_name(char *argv[])
{
    ft_putstr(argv[0]);
    write(1, "\n", 1);
}
//Exercise 01 : ft_print_params
/*
- Create a program that displays its given arguments.
- One per line, in the same order as in the command line.
- It should display all arguments, except for argv[0].
*/
void ft_print_params(int argc, char *argv[])
{
    for(int i = 1; i < argc; ++i)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
    }
}
//Exercise 02 : ft_rev_params
/*
• Create a program that displays its given arguments.
• One per line, in the reverse order of the command line.
• It should display all arguments, except for argv[0].
*/
void ft_rev_params(int argc, char *argv[])
{
    for(int i = argc - 1; i >= 1; --i)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
    }
}
//Exercise 03 : ft_sort_params
/*
• Create a program that displays its given arguments sorted by ascii order.
• It should display all arguments, except for argv[0].
• One argument per line.
*/
int ft_sort_ascii(int size, char *argv)
{
    char tmp;
    for(int i = 1; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            printf("i is %d, j is %d\n", i, j);
            if(argv[i] > argv[j])
            {
                tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
        }
    }
    return 0;
}
enum Compare
{
    CMP_SWAP = 1,
    CMP_STAY = -1
};
int ft_strcmp2(const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        //If strings are same but s2 is shorter than s1 --> swap.
        if(s2[i] == '\0')
        {
            return CMP_SWAP;
        }
        //If char of s1 is 'larger' than that of s2 --> swap.
        if(s1[i] > s2[i])
        {
            return CMP_SWAP; 
        }
        //If char of s1 is smaller than that s2 --> don't swap.
        else if(s1[i] < s2[i])
        {
            return CMP_STAY;
        }
        ++i;
    }
    return CMP_STAY;
}
void ft_sort_params(int argc, char *argv[])
{
    int i = 1;
    char *p_tmp;
    while(i < argc - 1)
    {
        int j = i + 1;
        while(j < argc)
        {
            if(ft_strcmp2(argv[i], argv[j]) > 0)
            {
                p_tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = p_tmp;
            }
            ++j;
        }
        ++i;
    }
    for(int i = 1; i < argc; ++i)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
    }
}

int main(int argc, char *argv[])
{
    /*ft_print_program_name(argv);
    ft_print_params(argc, argv);
    ft_rev_params(argc, argv);*/
    ft_sort_params(argc, argv);
    return 0;
}