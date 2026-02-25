#include <unistd.h>
#include <fcntl.h>
#include "ft_display_file.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

void ft_putnstr(char *str, int length)
{
    if(length <= 0)
    {
        return;
    }
    write(1, str, length);
}
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        char msg[] = "File name missing.\n";
        write(1, &msg, sizeof(msg));
    }
    else if(argc > 2)
    {

        char msg[] = "Too many arguments\n";
        write(1, &msg, sizeof(msg));
    }
    else
    {
        char buf[MAX_LEN];
        int fd = open(argv[1], O_RDONLY);
        if(fd == -1)
        {
            //printf("\nError: %d, reason: %s\n", errno, strerror(errno));
            char msg[] = "Cannot read file\n";
            write(1, &msg, sizeof(msg));
            return 0;
        }
        ssize_t count;
        while ((count = read(fd, buf, sizeof(buf))) > 0)
        {
            ft_putnstr(buf, MAX_LEN);
        }
        if(count == -1)
        {
            char msg[] = "Cannot read file\n";
            write(1, &msg, sizeof(msg));
        }
        close(fd);
    }
    return 0;
}