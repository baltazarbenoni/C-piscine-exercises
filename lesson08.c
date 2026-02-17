#include "ft_stock_str.h"
#include <stdlib.h>
#include "str_utils.h"
#include "io_utils.h"
#include <unistd.h>
//Exercise 04 : ft_strs_to_tab
/*
Create a function that takes an array of string as argument and the size of this array.
• It will transform each element of av into a structure.
• It should keep the order of av.
• The returned array should allocated in memory and its last element’s str set to 0, this will mark the end of the array.
• It should return a NULL pointer if an error occurs.
• We’ll test your function with our ft_show_tab (next exercise). Make it work according to this !
*/
static void ft_free_stock_str(t_stock_str *tab, int limit)
{
    int k = 0;
    if(!tab)
    {
        return;
    }
    while(k < limit)
    {
        free(tab[k].copy);
        ++k;
    }
    free(tab);
}
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    if(!av)
    {
        return NULL;
    }
    if(ac < 0)
    {
        return NULL;
    }
    int i = 0;
    t_stock_str *array = malloc((ac + 1) * sizeof(t_stock_str));
    if(!array)
        return NULL;
    while(i < ac)
    {
        if(!av[i])
        {
            ft_free_stock_str(array, i);
            return NULL;
        }
        int size_o = ft_strlen(av[i]);
        array[i].size = size_o;
        array[i].str = av[i];
        array[i].copy = malloc(size_o + 1);
        if(!array[i].copy)
        {

            ft_free_stock_str(array, i);
            return NULL;
        }
        int j = 0;
        while(av[i][j] != '\0')
        {
            array[i].copy[j] = av[i][j];
            ++j;
        }
        array[i].copy[j] = '\0';
        ++i;
    }
    array[i].size = 0;
    array[i].str = NULL;
    array[i].copy = NULL;
    return array;
}
//Exercise 05 : ft_show_tab
/*
• Create a function that displays the content of the array created by the previous function.
• The structure will be the same as the previous exercise and will be defined in the ft_stock_str.h file
• For each element, we’ll display:
◦ the string followed by a ’\n’
◦ the size followed by a ’\n’
◦ the copy of the string (that could have been modified) followed by a ’\n’
• We’ll test your function with our ft_strs_to_tab (previous exercise). Make it work according to this !
*/
void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while(par[i].str)
    {
        ft_putstr(par[i].str);
        write(1, "\n", 1);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        if(par[i].copy)
        {
            ft_putstr(par[i].copy);
            write(1, "\n", 1);
        }
        ++i;
    }
}
int main()
{
    char *arr[5];
    arr[0] = "Hello";
    arr[1] = "World";
    arr[2] = " I ";
    arr[3] = " am ";
    arr[4] = " aliveee$$$€€€@@}]@++aliveee ";
    arr[5] = "jou";
    t_stock_str *array = ft_strs_to_tab(6, arr);
    ft_show_tab(array);
}