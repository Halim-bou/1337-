#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h" // Include your get_next_line header file here

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print each line
        free(line);         // Free the line after printing
    }

    close(fd);
    return 0;
}
