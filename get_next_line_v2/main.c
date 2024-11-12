#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h" // Include your get_next_line header file here

int main(void)
{
    int i = 0;
    int fd = open("file.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    if (fd == -1 || fd2 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    char *line2;
    while (((line = get_next_line(fd)) != NULL) || ((line2 = get_next_line(fd2)) != NULL))
    {
        printf("%i:%s", i++, line2);  // Print each line
        free(line2);         // Free the line after printing
        if ((line = get_next_line(fd)) != NULL)
        {
            printf("%i:%s", i++, line);
            free(line);
        }
    }

    close(fd);
    close(fd2);
    return 0;
}
