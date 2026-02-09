#ifndef MATH_UTILS_H 
#define MATH_UTILS_H

int ft_abs(int num);
void ft_print_ints(int *arr, int size);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
int ft_atoi(char *str);
char ft_get_char_in_base(int nbr, int base);
int ft_check_base(char* base, int len);
int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);
#endif