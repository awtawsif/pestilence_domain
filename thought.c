#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "thought.h"
#include "output.h"

void thought_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You choose the path of the mind, where reality is a fever dream, and knowledge itself is a disease.\nThe fog whispers secrets you feel compelled to believe.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“Can knowledge infect?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Yes, truth spreads like a plague\n2. No, truth purifies\n3. Only lies infect\n\n");
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
    if (choice[0] != '1')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your mind fractures under the weight of madness...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the labyrinth of your own thoughts.");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your clarity preserves your sanity.\n");
        print_formatted_message(WHITE, ITALIC, "Your vision flickers, and you question the solidity of the ground beneath you. The path ahead is a twisting maze of logic and illusion.\n");
    }
}
