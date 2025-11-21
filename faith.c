#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "faith.h"
#include "output.h"
#include "read_line.h"

void faith_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, read_line(17));
    pnl();
    print_formatted_message(RED, BOLD, read_line(18));
    print_formatted_message(WHITE, BOLD, read_line(19));
    pnl();
    print_formatted_message(BLUE, BOLD, read_line(20));
    print_formatted_message(BLUE, BOLD, read_line(21));
    print_formatted_message(BLUE, BOLD, read_line(22));
    pnl();
    print_formatted_message(YELLOW, BOLD, "Choose your answer (1, 2 or 3): ");
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
    if (choice != 2)
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your faith crumbles, leaving you in despair...");
        pnl();
        print_formatted_message(WHITE, ITALIC, "You are lost in the void of disbelief.");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your steadfast faith shields you from despair.");
        pnl();
        print_formatted_message(WHITE, ITALIC, read_line(23));
    }
}
