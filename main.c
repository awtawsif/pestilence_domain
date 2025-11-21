#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "output.h"
#include "colors.h"
#include "read_line.h"
#include "flesh.h"
#include "faith.h"
#include "thought.h"

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
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, read_line(1));
    pnl();
    pnl();
    print_formatted_message(WHITE, ITALIC, read_line(2));
    print_formatted_message(WHITE, ITALIC, read_line(3));
    pnl();
    print_formatted_message(RED, BOLD, read_line(4));
    print_formatted_message(WHITE, BOLD, read_line(5));
    pnl();
    print_formatted_message(WHITE, ITALIC, read_line(6));
    pnl();
    print_formatted_message(BLUE, BOLD, read_line(7));
    print_formatted_message(BLUE, BOLD, read_line(8));
    print_formatted_message(BLUE, BOLD, read_line(9));
    pnl();
    print_formatted_message(YELLOW, BOLD, "Choose your destiny (1, 2 or 3): ");
    int choice;
    scanf("%d", &choice);
    while (1)
    {
        if (choice == 1 || choice == 2 || choice == 3)
        {
            break;
        }
        else
        {
            pnl();
            print_formatted_message(RED, NULL, "Ignorant fool! Choose again (1, 2 or 3): ");
            scanf("%d", &choice);
        }
    }
    if (choice == 1)
        flesh_path();
    else if (choice == 2)
        faith_path();
    else if (choice == 3)
        thought_path();

    pnl();
    return 0;
}