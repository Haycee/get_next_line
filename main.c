#include "get_next_line.h"

#include <stdio.h>

int main()
{
    int     fd[3];
    int     i;
    char    *str;

    fd[0] = open("test.txt", O_RDONLY);
    fd[1] = open("test2.txt", O_RDONLY);
    fd[2] = open("test3.txt", O_RDONLY);
    i = 0;

        str = get_next_line(fd[0]);
        printf("fd[0] = %s", str);
        str = get_next_line(fd[1]);
        printf("fd[1] = %s", str);
        str = get_next_line(fd[1]);
        printf("fd[1] = %s", str);
        str = get_next_line(fd[1]);
        printf("fd[1] = %s", str);
        str = get_next_line(fd[0]);
        printf("fd[0] = %s", str);
        str = get_next_line(fd[2]);
        printf("fd[2] = %s", str);
        str = get_next_line(fd[2]);
        printf("fd[2] = %s", str);
    return (0);
}
