#include <stdio.h>
#include "output.h"

#define RESET "\033[0m"
void print_formatted_message(char color[], char style[], char message[])
{
    if (style == NULL)
        style = "";

    printf("%s%s%s%s", color, style, message, RESET);
}

void pnl()
{
    printf("\n");
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