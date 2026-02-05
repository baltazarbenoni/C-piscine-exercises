#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "io_utils.h"
#include "str_utils.h"

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