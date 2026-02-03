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
void ft_sort_params(int argc, char *argv[])
{
    
}

int main(int argc, char *argv[])
{
    /*ft_print_program_name(argv);
    ft_print_params(argc, argv);
    ft_rev_params(argc, argv);*/
    return 0;
}