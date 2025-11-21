#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "flesh.h"
#include "output.h"

void flesh_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You choose the path of the body, the immediate, sickening truth of physical corruption.\nThe air grows heavier, and your own skin begins to prickle with fever.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“When flesh fails, what kills first?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. The wound itself\n2. The infection within\n3. The fear of dying\n\n");
    print_formatted_message(YELLOW, BOLD, "Choose your answer (1, 2 or 3): ");
    char choice[10];
    scanf("%s", choice);
    while (1)
    {
        if ((choice[0] == '1' || choice[0] == '2' || choice[0] == '3') && choice[1] == '\0')
        {
            break;
        }
        else
        {
            pnl();
            print_formatted_message(RED, NULL, "Ignorant fool! Choose again (1, 2 or 3): ");
            scanf("%s", choice);
        }
    }
    if (choice[0] != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your flesh trembles and decays rapidly...\n");
        print_formatted_message(WHITE, ITALIC, "You have succumbed to the plague of your own making.\n");
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your choice spares you from immediate decay.\n");
        print_formatted_message(WHITE, ITALIC, "You feel a subtle, painful shift in your bones, a silent acknowledgement of the unseen enemy.\nThe path ahead is now a labyrinth of physical distress.\n");
    }
}
