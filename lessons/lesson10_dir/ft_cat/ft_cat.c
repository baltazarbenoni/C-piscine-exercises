#include "ft_cat.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
/*
Exercise 01
Allowed functions : close, open, read, write, strerror, basename

• Create a program called ft_cat which does the same thing as the system’s cat command-line.
• You don’t have to handle options.
• The submission directory should have a Makefile with the following rules : all, clean, fclean.
• You may use the variable errno (check the man for Errno).
• You should read the man of all the authorized functions
• You can only do this exercise by declaring a fixed-sized array. This array will have a size limited to a little less than 30 ko. In order to test that size-limit, use the ulimit command-line in your Shell.
====================================================================
NAME: cat - concatenate files and print on the standard output
SYNOPSIS: cat [OPTION]... [FILE]...

DESCRIPTION: Concatenate FILE(s) to standard output.
       With no FILE, or when FILE is -, read standard input.
*/
void ft_display_input()
{
    char c;
    while(read(STDIN_FILENO, &c, 1) > 0)
    {
        write(1, &c, 1);
    }
}
int ft_str_is_same(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        if(s2[i] != s1[i])
        {
            return -1;
        }
        ++i;
    }
    return 0;
}
int main(int argc, char **argv)
{
    printf("Arg amount is %d\n", argc);
    if(argc < 2)
    {
        printf("Too little arguments, printing input stream\n");
        ft_display_input();
        return 0;
    }
    int i = 1;
    while(i < argc)
    {
        printf("Arg %d is %s\n", i, argv[i]);
        if(ft_str_is_same("-", argv[i]) == 0)
        {
            ft_display_input();
        }
        else
        {
            ft_display_file(argv[i]);
        }
        ++i;
    }
    return 0;
}