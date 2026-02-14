#include "ft_boolean.h"
#include <unistd.h>

void ft_putstrbool(char *str)
{
    while (*str)
    write(1, str++, 1);
}
t_bool ft_is_even(int nbr)
{
    return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstrbool(EVEN_MSG);
    else
        ft_putstrbool(ODD_MSG);
    return (SUCCESS);
}