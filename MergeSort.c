#include <unistd.h>
#include <stdio.h>
#include <limits.h>
/*

*/
void copy_array(int *copied, int *destination, int size, int start_index)
{
    for(int i = 0; i < size; ++i)
    {
        destination[start_index + i] = copied[i];
    }
}

void merge(int *left, int *right, int right_size, int left_size, int *result, int result_size)
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
    }
    if(right_size < 1)
    {
        copy_array(left, result, left_size, 0);
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
int get_next_index(int current, int step_size)
{
    int next = current + step_size;
    return next;
}
int append_array(int *copied, int start_from, int copy_length, int size, int *destination, int write_from)
{
    int element_count = 0;
    int end_index = copy_length + start_from;
    if(start_from >= size)
    {
        return;
    }
    if(copy_length + start_from >= size || write_from + copy_length >= size)
    {
        end_index = size;
    }
    for(int i = start_from, j = write_from; i < end_index; ++i, ++j)
    {
        destination[j] = copied[i];
        ++element_count;
    }
    return element_count;
}
void iterate(int step_size, int *buffer, int *left_buffer, int *right_buffer, int *result, int size)
{
    if(step_size >= size)
    {
        return;
    }
    int left_index = 0;
    int right_index = get_next_index(left, step_size);
    int copied_elements = 0;
    int buffer_start_index = 0;
    while(copied_elements < size)
    {
        int left_size = append_array(buffer, left_index, step_size, size, left_buffer, 0);
        int right_size = append_array(buffer, right_index, step_size, size, right_buffer, 0);
        merge(left_buffer, right_buffer, right_size, left_size, result, left_size + right_size);
        buffer_start_index += left_size + right_size;
        append_array(result, 0, left_size + right_size, size, buffer, buffer_start_index);
        copied_elements += right_size + left_size; 
        left_index = get_next_index(right_index, step_size);
        right_index = get_next_index(left_index, step_size);
    }
}
//number of subarrays: total number / 2 + total number % 2.
//
//

1, 1
1, 1
1, 1
1, 1
1, 1
1, 1
1, 0

2, 2
2, 2
2, 2
1, 0

4, 4
4, 1

8, 5

13

