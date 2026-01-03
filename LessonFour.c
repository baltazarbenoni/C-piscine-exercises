#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//Exercise 00 : ft_strcmp
//Reproduce the behavior of the function strcmp (man strcmp).
/*
strcmp() returns an integer indicating the result of the
       comparison, as follows:
       •  0, if the s1 and s2 are equal;
       •  a negative value if s1 is less than s2;
       •  a positive value if s1 is greater than s2.
*/
int ft_strcmp(char *s1, char *s2)
{
    if(s1[0] == '\0' && s2[0] == '\0')
    {
        return 0;
    }
    int counter1 = 0;
    int counter2 = 0;
    while(s1[counter1] != '\0')
    {
        ++counter1;
    }
    while(s2[counter2]!= '\0')
    {

        ++counter2;
        if(counter2 > counter1)
        {
            return -1;
        }
    }
    if(counter1 > counter2)
    {
        return 1;
    }
    else if(counter1 < counter2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
//Exercise 01 : ft_strncmp
//Reproduce the behavior of the function strncmp (man strncmp).
/*
    The strncmp() function is similar (to strcmp), except it compares only the first (at most) n bytes of s1 and s2.
*/
int ft_strncmp(char *s1, char *s2, unsigned int n)
{

}



int main()
{
    char str1[] = "hello all my friends!";
    char str2[] = "hello all m";
    printf("%d", ft_strcmp(str1, str2));
    
    return 0;
}


