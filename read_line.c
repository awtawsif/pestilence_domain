#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"

char *read_line(int line_number)
{
    FILE *file;
    int current_line = 1;
    int keep_reading = 1;
    char return_text[1024];
    char contents[1024];
    file = fopen("story.txt", "r");
    while (keep_reading)
    {
        fgets(contents, 1024, file);
        if (current_line == line_number)
        {
            keep_reading = 0;
            fclose(file);
            char *result = malloc(strlen(contents) + 1);
            strncpy(result, contents, strlen(contents) + 1);
            return result;
        }
        current_line++;
    }
}
