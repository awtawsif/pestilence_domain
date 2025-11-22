#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "thought.h"
#include "output.h"
#include "choose.h"

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
    char choice = choose_path(3);
    if (choice != '1')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your mind fractures under the weight of madness...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the labyrinth of your own thoughts.");
        pnl();
        print_death_ascii_art();
        pnl();
        usleep(500000);
        exit(0);
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
    char choice = choose_path(3);
    if (choice == '1')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to follow the echo.\n");
        pnl();
        exit(0);
    }
    else if (choice == '2')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to block your ears.\n");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to scream back.\n");
        pnl();
        exit(0);
    }
}