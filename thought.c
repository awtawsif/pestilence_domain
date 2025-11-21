#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "thought.h"
#include "output.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\033[H\033[J")
#endif

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
        // TODO: Add a death ascii art here later
        // TODO: Add a delay before exit
        // TODO: Maybe add a restart option later
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your clarity preserves your sanity.\n");
        print_formatted_message(WHITE, ITALIC, "Your vision flickers, and you question the solidity of the ground beneath you. The path ahead is a twisting maze of logic and illusion.\n");
        hall_of_echoes();
    }
}

void hall_of_echoes()
{
    clrscr();
    print_ascii_art();
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, "##############################\n");
    print_formatted_message(GREEN, BOLD, "##### The Hall of Echoes #####\n");
    print_formatted_message(GREEN, BOLD, "##############################\n\n");
    print_formatted_message(WHITE, ITALIC, "You arrive at a hall shrouded in mist, where every sound is amplified into a cacophony of whispers.\n");
    print_formatted_message(WHITE, ITALIC, "The Hall is vast and empty. The air repeats your every thought—each echo louder, more twisted, and more accusatory than the last.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“In this din of self-condemnation, how do you react to the echoes?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Follow the echo\n2. Block your ears\n3. Scream back\n\n");
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
}