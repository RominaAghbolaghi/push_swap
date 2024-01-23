#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    fd = open("./file1.txt", O_RDONLY);
    while(1)
    {
        line = get_next_line(fd);
            if (!line)
                break ;
            printf("%s", line);
            free(line);
    }
    printf("%s", line);
    close(fd);

    return (0);
}
