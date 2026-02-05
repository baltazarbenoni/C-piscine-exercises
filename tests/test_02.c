#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    char source[] = "hei minun nimeni on jaakko";
    char dest[40] = "joujouuu"; 
    char test[] = "lksajdflksjaflkjp";
    char test2[] = "lksf9034l";
    char test3[] = "";
    char test4[] = "120934345943";
    ft_strncpy(dest, source, 30);
    ft_putstr(dest);
    /*printf("%d\n", ft_str_is_alpha(test));
    printf("%d\n", ft_str_is_alpha(test2));
    printf("%d\n", ft_str_is_alpha(dest));
    printf("%d\n", ft_str_is_alpha(test3));
    printf("%d\n", ft_str_is_numeric(test3));
    printf("%d\n", ft_str_is_numeric(test4));
    printf("%d\n", ft_str_is_numeric(test));
    */
    write(1, "\n", 1);
    ft_putstr(ft_strupcase(test));
    write(1, "\n", 1);
    ft_putstr(ft_strlowcase(test));
    write(1, "\n", 1);
    ft_putstr(ft_strcapitalize(test));
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    write(1, "\n", 1);
    ft_putstr(ft_strcapitalize(str));
    char str2[] = "Coucou\ntu vas bien ?";
    write(1, "\n", 1);
    ft_putstr_non_printable(str2);

    return 0;
}
