#include <unistd.h>
#include <stdbool.h>

int ft_check_for_queens(int x, int y, int *queens)
{
    int current_size = x;
    for(int i = 0; i < current_size; ++i)
    {
        //Check if this y-row is free.
        if(queens[i] == y)
        {
            return 0;
        }
        //Check diagonals.
        if(ft_abs(queens[i]- y) == ft_abs(i - x))
        {
            return 0;
        }
    }
    return 1;
}
enum SolveResult
{
    SOLVE_BACKTRACK,
    SOLVE_ADVANCE,
    SOLVE_CONTINUE_COLUMN,
    SOLVE_BACKTRACK_AFTER_SOLUTION,
    SOLVE_DONE
};
int ft_queen_solver(int column, int* queens, int size)
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
            return SOLVE_DONE;
        }
        //Returning zero causes backtrack.
        return SOLVE_BACKTRACK;
    }
    //Check if there are any options above current queen y-value (or zero).
    for(int i = start; i < size; ++i)
    {
        if(ft_check_for_queens(column, i, queens) == 1)
        {
            //Free cell found, store value in queens.
            queens[column] = i;
            //If completed, break and add this configuration to solutions.
            if(column == size - 1)
            {
                for(int j = 0; j < size; ++j)
                {
                    ft_putnbr(queens[j]);
                    if(j == size - 1)
                    {
                        write(1, "\n", 1);
                    }
                    else
                    {
                        char cln = ',';
                        write(1, &cln, 1);
                    }
                }
                //Return value 3 causes backtracking from correct solution.
                if(queens[column] == size - 1)
                {
                    queens[column] = -1;
                    return SOLVE_BACKTRACK_AFTER_SOLUTION;
                }
                //Return value 2 --> check other cells in this column.
                else
                {
                    return SOLVE_CONTINUE_COLUMN;
                }
            }
            //Else continue, go to next column.
            else
            {
                //Returning 1 causes program to advance 'deeper'.
                return SOLVE_ADVANCE;
            }
        }
        //this means dead end --> backtrack and remove queen from current column.
        else if(i == size - 1)
        {
            if(column <= 0)
            {
                return SOLVE_DONE;
            }
            queens[column] = -1;
            //Returning zero causes backtrack.
            return SOLVE_BACKTRACK;
        }
    }
    char str[] = "End of loop, returning 0\n"; 
    ft_putstr(str);
    return SOLVE_DONE;
}
int ft_manage_queen_loop(int *queens, int size, int *solution_count)
{
    int column = 1;
    int result = 0;
    while(result != SOLVE_DONE)
    {
        //Check column is assigned correctly.
        if(column < 0 || column >= size)
        {
            char str[] = "Incorrect column index, returning...\n";
            ft_putstr(str);
            return 0;
        }
        //Run one iteration.
        result = ft_queen_solver(column, queens, size);
        //If result is 0, backtrack.
        if(result == SOLVE_BACKTRACK)
        {
            column -= 1;
        }
        //If result is 1, go deeper.
        else if(result == SOLVE_ADVANCE)
        {
            column += 1;
        }
        else if(result == SOLVE_BACKTRACK_AFTER_SOLUTION || result == SOLVE_CONTINUE_COLUMN)
        {
            *solution_count += 1;
            char msg[] = "\nFound solution, count is: ";
            ft_putstr(msg);
            ft_putnbr(*solution_count);
            write(1, "\n", 1);
            //If result is 3, backtrack from correct solution.
            if(result == SOLVE_BACKTRACK_AFTER_SOLUTION)
            {
                column -= 1;
            }
            //If result is 2, loop was successfully completed, try other options in the last column.
            else
            {
                continue;
            }
        }
    }
    //If result is -1, backtracking is complete, loop is broken, return 0.
    return 0;
}
void ft_ten_queens_puzzle(void)
{
    int solution_count = 0;
    int queens[10];
    int result = 0;
    queens[0] = 0;
    //Initialize array//.
    for(int i = 1; i < 10; ++i)
    {
        queens[i] = -1;
    }
    int *ptr = &solution_count;
    result = ft_manage_queen_loop(queens, 10, ptr);
    char line[] = "=====================================";
    ft_putstr(line);
    char msg[] = "Final solution count is: ";
    ft_putstr(msg);
    ft_putnbr(solution_count);
    write(1, "\n", 1);
}
void ft_n_queens_puzzle(int n)
{
    int upper_limit = 13;
    if(n == 0 || n > upper_limit)
    {
        return;
    }
    int solution_count = 0;
    int queens[n];
    int result = 0;
    queens[0] = 0;
    //Initialize array//.
    for(int i = 1; i < n; ++i)
    {
        queens[i] = -1;
    }
    int *ptr = &solution_count;
    result = ft_manage_queen_loop(queens, n, ptr);
    char line[] = "=====================================";
    ft_putstr(line);
    char msg[] = "Final solution count is: ";
    ft_putstr(msg);
    ft_putnbr(solution_count);
    write(1, "\n", 1);
}