#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("don_quijote.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error abriendo el archivo");
        return (1);
    }

    printf("=== Probando get_next_line con Don Quijote ===\n\n");

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
