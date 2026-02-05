#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "io_utils.h"

int main()
{
    int num = 11;
    printf("Iterative: %d, recusive: %d factorial\n", ft_iterative_factorial(num), ft_recursive_factorial(num));
    int nb = 5;
    int pow = 4;
    printf("Iterative power of %d over %d is %d\n", nb, pow, ft_iterative_power(nb, pow));
    printf("Factorial power of %d over %d is %d\n", nb, pow, ft_recursive_power(nb, pow));
    int index = 10;
    printf("Fibonacci for index %d is %d\n", index, ft_fibonacci(index));
    int result = ft_sqrt(25);
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
    printf("\nResult for %d squared is: %d\n", 13, result);
    ft_is_prime(19);
    ft_is_prime(47);
    ft_is_prime(111);
    ft_find_next_prime(4);
    ft_find_next_prime(15);
    ft_find_next_prime(106);
    ft_find_next_prime(115);
    ft_find_next_prime(165);
    return 0;
}