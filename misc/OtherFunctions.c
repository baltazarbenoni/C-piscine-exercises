#include <unistd.h>
#include <stdio.h>
#include <limits.h>
/*
    int a = 12;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;
    int ********ptr8 = &ptr7;
    int *********ptr9 = &ptr8;
    ft_ultimate_ft(ptr9);
    printf("%d", a);
 
*/
int power(int num, int power)
{
    int result = 1;
    if(power < 1)
    {
        return result;
    }
    else
    {
        for(int i = 1; i <= power; ++i)
        {
            result = result * num;
        }
    }
    printf("%d", result);
    printf("\n");
}
int get_abs(int num)
{
    if(num < 0)
    {
        return num * -1;
    }
    else
    {
        return num;
    }
}