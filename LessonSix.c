#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "mylib.h"
//Exercise 00 : ft_iterative_factorial
/*
Create an iterated function that returns a number. This number is the result of a
factorial operation based on the number given as a parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/
int ft_iterative_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    for(int i = 1; i < nb; ++i)
    {
        product *= i;
    }
    return product;
}
//Exercise 01 : ft_recursive_factorial
/*
Create a recursive function that returns the factorial of the number given as a
parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/
int ft_recursive_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    while(nb > 1)
    {
        nb = nb - 1;
        product *= nb;
    }
    return product;
}
//Exercise 02 : ft_iterative_power
/*
Create an iterated function that returns the value of a power applied to a number.
An power lower than 0 returns 0. Overflows must not be handled.
• We’ve decided that 0 power 0 will returns 1
*/
int ft_iterative_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    int result = 1;
    for(int i = 0; i < power; ++i)
    {
        result *= nb;
    }
    return result;
}
//Exercise 03 : ft_recursive_power
/*
Create a recursive function that returns the value of a power applied to a number.
• Overflows must not be handled, the function return will be undefined.
• We’ve decided that 0 power 0 will returns 1
*/
int ft_recursive_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    int result = 1;
    while(power > 0)
    {
        result *= nb;
        power -= 1;
    }
    return result;
}
//Exercise 04 : ft_fibonacci
/*
Create a function ft_fibonacci that returns the n-th element of the Fibonacci
sequence, the first element being at the 0 index. We’ll consider that the Fibonacci
sequence starts like this: 0, 1, 1, 2.
• Overflows must not be handled, the function return will be undefined.
• Obviously, ft_fibonacci has to be recursive.
• If the index is less than 0, the function should return -1.
*/
int ft_fibonacci(int index)
{
    if(index < 0)
    {
        return -1;
    }
    int previous = 0;
    int element = 1;
    int temp = 0;
    while(index > 0)
    {
        temp = element;
        element += previous;
        previous = temp;
        --index;
    }
    return element;
}
//Exercise 05 : ft_sqrt
//Create a function that returns the square root of a number (if it exists), or 0 if the square root is an irrational number.
int ft_sqrt(int nb)
{
    if(nb == 1)
    {
        return 1;
    }
    int root = nb / 2;
    int previous = 0;
    while(root * root != nb)
    {
        previous = root;
        //Using Newton's method.
        root = (root + nb / root) / 2;
        //If not converging --> has no retional root, exit loop.
        if(root == previous && root * root != nb)
        {
            return 0;
        }
    }
    return root;
}
//Exercise 06 : ft_is_prime
//Create a function that returns 1 if the number given as a parameter is a prime number, and 0 if it isn’t.
int ft_is_prime(int nb)
{
    if(nb < 2)
    {
        return 0;
    }
    if(nb == 2)
    {
        return 1;
    }
    for(int i = 2; i < nb; ++i)
    {
        if(nb % i == 0)
        {
            //printf("Found divider %d, %d is not prime\n", i, nb);
            return 0;
        }
    }
    //printf("Not divider found, %d is prime\n", nb);
    return 1;
}
//Exercise 07 : ft_find_next_prime
// Create a function that returns the next prime number greater or equal to the number given as argument.
int ft_find_next_prime(int nb)
{
    if(ft_is_prime(nb) == 1)
    {
        //printf("nb %d is prime\n", nb);
        return nb;
    }
    while(ft_is_prime(nb) != 1)
    {
        nb += 1;
        //printf("Trying if %d is prime\n", nb);
    }
    //printf("Found! %d is prime\n", nb);
    return nb;
}
//Exercise 08 : The Ten Queens
/*
Create a function that displays all possible placements of the ten queens on a
chessboard which would contain ten columns and ten lines, without them being
able to reach each other in a single move, and returns the number of possibilities.
• Recursivity is required to solve this problem.
• Here’s how it’ll be displayed :
$>./a.out | cat -e
0257948136$
0258693147$
...
4605713829$
4609582731$
...
9742051863$
$>
• The sequence goes from left to right. The first digit represents the first Queen’s
position in the first column (the index starting from 0). The Nth digit represents
the Nth Queen’s position in the Nth column.
• The return value must be the total number of displayed solutions.
*/
int check_for_queens(int x, int y, int *queens)
{
    int current_size = x;
    for(int i = 0; i < current_size; ++i)
    {
        //Check if this y-row is free.
        if(queens[i] == y)
        {
            //printf("Found previous queen at %d, %d", i, y);
            return 0;
        }
        //Check diagonals.
        if(ft_abs(queens[i]- y) == ft_abs(i - x))
        {
            //printf("found previous queen at {%d}, {%d}.", x, y);
            return 0;
        }
    }
    return 1;
}
//Currently backtracking and going forward happen inside the loop --> big problems.
//Return a flag value --> operate based on that.
int solve(int column, int* queens, int size)
{
    //start is 0 if queens is empty (-1) at this column, else its one larger than the current value.
    int start = queens[column] + 1;
    //If all the cells on this column have been checked, backtrack.
    if(queens[column] >= size - 1)
    {
        queens[column] = -1;
        //Do not backtrack if already at the first column.
        if(column <= 0)
        {
            return -1;
        }
        //Returning zero causes backtrack.
        return 0;
    }
    //Check if there are any options above current queen y-value (or zero).
    for(int i = start; i < size; ++i)
    {
        if(check_for_queens(column, i, queens) == 1)
        {
            //Free cell found, store value in queens.
            queens[column] = i;
            //If completed, break and add this configuration to solutions.
            if(column == size - 1)
            {
                for(int i = 0; i < size; ++i)
                {
                    printf("%d", queens[i]);
                    if(i == size - 1)
                    {
                        printf("\n");
                    }
                    else
                    {
                        printf(",");
                    }
                }
                //Return value 2 causes returning back to top to get new start value.
                return 2;
            }
            //Else continue, go to next column.
            else
            {
                //Returning 1 causes program to advance 'deeper'.
                return 1;
            }
        }
        //this means dead end --> backtrack and remove queen from current column.
        else if(i == size - 1)
        {
            if(column <= 0)
            {
                printf("Column 0, cannot backtrack, end of search.\n");
                return -1;
            }
            //printf("Backtracking to column %d\n", column - 1);
            queens[column] = -1;
            //Returning zero causes backtrack.
            return 0;
        }
    }
    printf("End of loop, returning 0");
    return -1;
}
int manage_loop(int *queens, int size)
{
    int column = 1;
    int result = 0;
    while(result >= 0)
    {
        //Check column is assigned correctly.
        if(column < 0 || column >= size)
        {
            printf("Incorrect column index: %d, returning...\n", column);
            return 0;
        }
        //Run one iteration.
        result = solve(column, queens, size);
        //If result is 0, backtrack.
        if(result == 0)
        {
            column -= 1;
        }
        //If result is 1, go deeper.
        else if(result == 1)
        {
            column += 1;
        }
        //If result is 2, loop was successfully completed, return to beginning.
        else if(result == 2)
        {
            return 1;
        }
    }
    //If result is -1, loop is broken, return 0.
    return 0;
}
int ft_ten_queens_puzzle(void)
{
    int solution_count = 0;
    int queens[10];
    int result = 0;
    printf("Now entering loop!");
    //Start the loop from index 1 since index 0 is initialized to 0.
    //for(int start_val = 0; start_val < 10; ++start_val)
    while(result != 0)
    {
        queens[0] = start_val;
        //Initialize array.
        for(int i = 1; i < 10; ++i)
        {
            queens[i] = -1;
        }
        result = manage_loop(queens, 10);
        printf("Result is %d", result);
        if(result == 0)
        {
            printf("Something went wrong..");
            break;
        }
        ++solution_count;
        printf("Start val is %d, solution count is %d\n", start_val, solution_count);
    }
    printf("Solution count is %d.\n", solution_count);
    return solution_count;
}


int main()
{
    /*int num = 11;
    printf("Iterative: %d, recusive: %d factorial\n", ft_iterative_factorial(num), ft_recursive_factorial(num));
    int nb = 5;
    int pow = 4;
    printf("Iterative power of %d over %d is %d\n", nb, pow, ft_iterative_power(nb, pow));
    printf("Factorial power of %d over %d is %d\n", nb, pow, ft_recursive_power(nb, pow));
    int index = 10;
    printf("Fibonacci for index %d is %d\n", index, ft_fibonacci(index));*/
    /*int result = ft_sqrt(25);
    printf("\nResult for %d squared is: %d\n", 25, result);
    result = ft_sqrt(36);
    printf("\nResult for %d squared is: %d\n", 36, result);
    result = ft_sqrt(4);
    printf("\nResult for %d squared is: %d\n", 4, result);
    result = ft_sqrt(5);
    printf("\nResult for %d squared is: %d\n", 5, result);
    result = ft_sqrt(256);
    printf("\nResult for %d squared is: %d\n", 256, result);
    result = ft_sqrt(81);
    printf("\nResult for %d squared is: %d\n", 81, result);
    result = ft_sqrt(13);
    printf("\nResult for %d squared is: %d\n", 13, result);*/
    /*ft_is_prime(19);
    ft_is_prime(47);
    ft_is_prime(111);
    ft_find_next_prime(4);
    ft_find_next_prime(15);
    ft_find_next_prime(106);
    ft_find_next_prime(115);
    ft_find_next_prime(165);*/
    ft_ten_queens_puzzle();
    return 0;
}