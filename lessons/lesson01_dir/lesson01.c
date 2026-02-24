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
//=====================================
//Using merge-sort to solve the exercise.
#define MIN(a,b) ((a)<(b)?(a):(b)) 

void copy_array(int *copied, int *destination, int size, int start_index)
{
    for(int i = 0; i < size; ++i)
    {
        destination[start_index + i] = copied[i];
    }
}
void merge(int *left, int left_size, int *right, int right_size, int *result, int result_size)
{
    int full_size = left_size + right_size;
    if(result_size < full_size || full_size < 1)
    {
        return;
    }
    //===================================================
    //Handle empty arrays.
    if(left_size < 1)
    {
        copy_array(right, result, right_size, 0);
        return;
    }
    if(right_size < 1)
    {
        copy_array(left, result, left_size, 0);
        return;
    }
    //===================================================
    //Handle merge when both arrays are longer than 0.
    int left_index = 0;
    int right_index = 0;
    while(right_index < right_size && left_index < left_size)
    {
        if(left[left_index] >= right[right_index])
        {
            result[right_index + left_index] = right[right_index];
            ++right_index;
        }
        else
        {
            result[right_index + left_index] = left[left_index];
            ++left_index;
        }
    }
    //===================================================
    //Drain the remaining values into the result if one array is exhausted.
    if(left_index == left_size)
    {
        while(right_index < right_size)
        {
            result[right_index + left_index] = right[right_index];  
            ++right_index;
        }
    }
    else
    {
        while(left_index < left_size)
        {
            result[right_index + left_index] = left[left_index];  
            ++left_index;
        }
    }
}
void iterate_merge(int step_size, int *buffer, int *left_buffer, int *right_buffer, int *result, int size)
{
    if(step_size >= size)
    {
        return;
    }
    int left_index = 0;
    int right_index = left_index + step_size;
    int buffer_start_index = 0;
    while(buffer_start_index < size)
    {
        //=============================
        //If buffer bounds exceeded --> return.
        if(left_index >= size)
        {
            break;
        }
        //==============================
        //Copy left block from buffer.
        int left_block_length = MIN(step_size, size - left_index);
        for(int i = 0; i < left_block_length; ++i)
        {
            left_buffer[i] = buffer[left_index + i];
        }
        //==============================
        //If right index exceeds the bounds of the buffer, copy left block to result and return.
        int right_block_length = 0;
        if(right_index >= size)
        {
            for(int i = 0; i < left_block_length; ++i)
            {
                buffer[buffer_start_index + i] = left_buffer[i];
            }
            buffer_start_index += left_block_length;
            break;
        }
        //==============================
        //Get right block.
        right_block_length = MIN(step_size, size - right_index);
        for(int i = 0; i < right_block_length; ++i)
        {
            right_buffer[i] = buffer[right_index + i];
        }
        //==============================
        //Merge and sort the two copied arrays
        int merge_block_length = left_block_length + right_block_length;
        merge(left_buffer, left_block_length, right_buffer, right_block_length, result, merge_block_length);
        //==============================
        //Copy the merged array to buffer
        for(int i = 0; i < merge_block_length; ++i)
        {
            buffer[buffer_start_index + i] = result[i];
        }
        buffer_start_index += merge_block_length;
        //=============================
        //Increase indices.
        left_index = buffer_start_index;
        right_index = left_index + step_size;
        //================================
    }
}
//Merge-sort function to sort small arrays (arrays allocated on stack).
void ft_sort_int_tab(int *buffer, int size)
{
    int result[size];
    int left_buffer[size];
    int right_buffer[size];
    int step_size = 1;
    while(step_size < size)
    {
        iterate_merge(step_size, buffer, left_buffer, right_buffer, result, size);
        step_size *= 2;
    }
}
void print_sorted_array(int *ar, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d", ar[i]);
        if(i < size - 1)
        {
            printf(", ");
        }
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
    printf("\nCount is : %d\n", count);
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft_rev_int_tab(ar, 10);
    //==============================
    int array_to_merge[12] = {1, 6, 34, 2, 7, 65, 43, 3, 88, 13, 42, 35};
    ft_sort_int_tab(array_to_merge, 12);
    print_sorted_array(array_to_merge, 12);
    return 0;
}