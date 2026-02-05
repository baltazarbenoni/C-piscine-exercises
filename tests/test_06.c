#include "program_utils.h"

int main(int argc, char *argv[])
{
    ft_print_program_name(argv);
    ft_print_params(argc, argv);
    ft_rev_params(argc, argv);
    ft_sort_params(argc, argv);
    return 0;
}