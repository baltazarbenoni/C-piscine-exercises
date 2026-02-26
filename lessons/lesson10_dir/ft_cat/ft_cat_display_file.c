#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "ft_cat.h"
#include "str_utils.h"

void ft_putnstr(char *str, int length)
{
    if(length <= 0)
    {
        return;
    }
    write(1, str, length);
}
int ft_cat_display_file(char *arg)
{
    char buf[MAX_LEN];
    int fd = open(arg, O_RDONLY);
    if(fd == -1)
    {
        char *error = "Error with file descriptor: ";
        write(1, error, ft_strlen(error));
        char *msg = strerror(errno);
        write(1, msg, ft_strlen(msg));
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
    return 0;
}