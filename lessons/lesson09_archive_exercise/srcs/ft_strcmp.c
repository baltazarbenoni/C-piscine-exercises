
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
    else
    {
        return 0;
    }
}