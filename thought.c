#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "thought.h"
#include "output.h"
#include "choose.h"

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
    int wisdom = 0;
    int choice_count = 3;
    int stages[3] = {0, 0, 0};
    while (stages[0] == 0 || stages[1] == 0 || stages[2] == 0)
    {
        clrscr();
        print_ascii_art();
        pnl();
        pnl();
        print_formatted_message(GREEN, BOLD, "#############################\n");
        print_formatted_message(GREEN, BOLD, "##### The Hall of Echoes #####\n");
        print_formatted_message(GREEN, BOLD, "##############################\n\n");
        print_formatted_message(WHITE, ITALIC, "You arrive at a hall shrouded in mist, where every sound is amplified into a cacophony of whispers.\n");
        print_formatted_message(WHITE, ITALIC, "The Hall is vast and empty. The air repeats your every thought—each echo louder, more twisted, and more accusatory than the last.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“In this din of self-condemnation, how do you react to the echoes?”\n\n");
        if (stages[0] == 0)
            print_formatted_message(BLUE, BOLD, "Follow the echo\n");
        if (stages[1] == 0)
            print_formatted_message(BLUE, BOLD, "Block your ears\n");
        if (stages[2] == 0)
            print_formatted_message(BLUE, BOLD, "Scream back\n\n");

        char choice = choose_path(choice_count);
        if (choice == '1' && stages[0] == 0)
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to follow the echo.\n");
            print_formatted_message(WHITE, ITALIC, "Your younger self appears, naive and accusing.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Is the past self a key or a hindrance to your wisdom?”\n\n");
            print_formatted_message(BLUE, BOLD, "Embrace\nReject\n\n");
            choice = choose_path(2);
            if (choice == '1')
            {
                wisdom += 1;
                stages[0] = 1;
            }
            else if (choice == '2')
            {
                stages[0] = 1;
            }
            choice_count--;
            pnl();
        }
        else if (stages[1] == 0 && (choice == '2' && stages[0] == 0) || (choice == '1' && stages[0] == 1))
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to block your ears.\n");
            print_formatted_message(WHITE, ITALIC, "Internal rhythm becomes unavoidable.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you accept this new internal rhythm?”\n\n");
            print_formatted_message(BLUE, BOLD, "Listen\nPanic\n\n");
            choice = choose_path(2);
            if (choice == '1')
            {
                wisdom += 1;
                stages[1] = 1;
            }
            else if (choice == '2')
            {
                stages[1] = 1;
            }
            choice_count--;
            pnl();
        }
        else if (stages[2] == 0 && ((choice == '3' && stages[0] == 0 && stages[1] == 0) || (choice == '2' && stages[0] == 1 && stages[1] == 0) || (choice == '2' && stages[0] == 0 && stages[1] == 1) || (choice == '1' && stages[0] == 1 && stages[1] == 1)))
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to scream back.\n");
            print_formatted_message(WHITE, ITALIC, "The echoes form a choir of madness.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“What is the only sane reaction?”\n\n");
            print_formatted_message(BLUE, BOLD, "Keep screaming\nLaugh\n\n");
            choice = choose_path(2);
            if (choice == '1')
            {
                wisdom += 1;
                stages[2] = 1;
            }
            else if (choice == '2')
            {
                stages[2] = 1;
            }
            choice_count--;
            pnl();
        }
    }
    if (wisdom >= 2)
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your mind is tested, and you emerge stronger.\n");
        pnl();
        print_win_ascii_art();
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your mind is tested, and you emerge weaker.\n");
        pnl();
        print_death_ascii_art();
        pnl();
        exit(0);
    }
}