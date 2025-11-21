#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "flesh.h"
#include "output.h"
#include "read_line.h"

void flesh_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, read_line(10));
    pnl();
    print_formatted_message(RED, BOLD, read_line(11));
    print_formatted_message(WHITE, BOLD, read_line(12));
    pnl();
    print_formatted_message(BLUE, BOLD, read_line(13));
    print_formatted_message(BLUE, BOLD, read_line(14));
    print_formatted_message(BLUE, BOLD, read_line(15));
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
        print_formatted_message(RED, BOLD, "Your flesh trembles and decays rapidly...");
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have succumbed to the plague of your own making.");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your choice spares you from immediate decay.");
        pnl();
        print_formatted_message(WHITE, ITALIC, read_line(16));
    }
}
