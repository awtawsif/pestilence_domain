#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "thought.h"
#include "output.h"
#include "read_line.h"

void thought_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, read_line(24));
    pnl();
    print_formatted_message(RED, BOLD, read_line(25));
    print_formatted_message(WHITE, BOLD, read_line(26));
    pnl();
    print_formatted_message(BLUE, BOLD, read_line(27));
    print_formatted_message(BLUE, BOLD, read_line(28));
    print_formatted_message(BLUE, BOLD, read_line(29));
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
    if (choice != 1)
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your mind fractures under the weight of madness...");
        pnl();
        print_formatted_message(WHITE, ITALIC, "You are lost in the labyrinth of your own thoughts.");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your clarity preserves your sanity.");
        pnl();
        print_formatted_message(WHITE, ITALIC, read_line(30));
    }
}
