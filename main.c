#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

void print_formatted_message(char color[], char style[], char message[])
{
    if (style == NULL)
        style = "";
    else if (style == "BOLD")
        style = BOLD;
    else if (style == "ITALIC")
        style = ITALIC;

    printf("%s%s%s%s", color, style, message, RESET);
}

void print_newline()
{
    printf("\n");
}

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
            strcpy(result, contents);
            return result;
        }
        current_line++;
    }
}

void print_ascii_art()
{
    printf("%s",
           " _____          _   _ _                        _____                        _       "
           "\n|  __ \\        | | (_) |                      |  __ \\                      (_)      "
           "\n| |__) |__  ___| |_ _| | ___ _ __   ___ ___   | |  | | ___  _ __ ___   __ _ _ _ __  "
           "\n|  ___/ _ \\/ __| __| | |/ _ \\ '_ \\ / __/ _ \\  | |  | |/ _ \\| '_ ` _ \\ / _` | | '_ \\ "
           "\n| |  |  __/\\__ \\ |_| | |  __/ | | | (_|  __/  | |__| | (_) | | | | | | (_| | | | | |"
           "\n|_|   \\___||___/\\__|_|_|\\___|_| |_|\\___\\___|  |_____/ \\___/|_| |_| |_|\\__,_|_|_| |_|"
           "\n");
}

int main()
{
    print_ascii_art();
    return 0;
}