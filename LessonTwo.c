#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//Exercise 00:
//Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
void ft_ft(int *nbr)
{
    *nbr = 42;
}
//Exercise 01:
//Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "42" to that int.
// --> 9 pointers
void ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
}
//Exercise 02:
//Create a function that swaps the value of two integers whose addresses are entered as parameters.
void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Exercise 03:
//Create a function ft_div_mod. This function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod.
void ft_div_mod(int a, int b, int *div, int *mod)
{
    *mod = a % b;
    *div = a / b;
}
//Exercise 04:
//Create a function ft_ultimate_div_mod. This function divides parameters a by b. The result of this division is stored in the int pointed by a. The remainder of the division is stored in the int pointed by b.
void ft_ultimate_div_mod(int *a, int *b)
{
    int tmp = *a;
    *a = *a / *b;
    *b = tmp % *b;
}
//Exercise 05:
//Create a function that displays a string of characters on the standard output.
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
//Exercise 06:
//Create a function that counts and returns the number of characters in a string.
int ft_strlen(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
    }
    return length_counter;
}
//Exercise 07:
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
//Exercise 08:
//Create a function which sorts an array of integers by ascending order. The arguments are a pointer to int and the number of ints in the array.
void ft_sort_int_tab(int *tab, int size)
{
    //Merge sort.
    for(int i = 0; i < size; ++i)
    {

    }
}
void print_array(int *ar, int size)
{
    for(int i = 0; i < size; ++i)
    {
        char c = '0' + ar[i];
        write(1, &c, 1);
        write(1, " ", 1);
    }
}
int main()
{
    int div = 0;
    int mod = 0;
    ft_div_mod(10, 3, &div, &mod);
    printf("result: %d, remainder: %d", div, mod);
    printf("\n");
    ft_div_mod(97, 17, &div, &mod);
    printf("result: %d, remainder: %d", div, mod);
    printf("\n");
    int a = 194;
    int b = 17;
    ft_ultimate_div_mod(&a, &b);
    printf("result: %d, remainder: %d", a, b);
    char str[] = "kakka";
    char str2[] = "29321jaaaksjda";
    ft_putstr(str);
    ft_putstr(str2);
    char str3[] = "kakkakakkakakkakakka";
    int count = ft_strlen(str3);
    printf("\nCount is : %d", count);
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft_rev_int_tab(ar, 10);
    print_array(ar, 10);
    return 0;
}