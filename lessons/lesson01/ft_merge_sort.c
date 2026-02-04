#include <unistd.h>
#include <stdio.h>
#include <limits.h>
//Exercise 08:
//Create a function which sorts an array of integers by ascending order. The arguments are a pointer to int and the number of ints in the array.
//=====================================
//Using merge-sort.
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