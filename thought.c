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
    print_formatted_message(WHITE, ITALIC, "You step into a fog that murmurs in languages you know and those you've never heard. Ideas feel like viruses here —\n contagious, seductive, altering the shape of questions until they bite.\nThe air tastes like old libraries and the metallic tang of revelation.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“Does knowing alter the knower, or merely reveal what already festers within?”\n\n");
    print_formatted_message(BLUE, BOLD, "Yes, truth spreads like a plague, changing all it touches\nNo, truth purifies — exposure cleanses corruption\nOnly lies infect — falsehood is the contagion of minds\n\n");
    char choice = choose_path(3);
    if (choice != '1')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your mind fractures under the weight of madness...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the labyrinth of your own thoughts.");
        pnl();
        pnl();
        print_death_ascii_art();
        pnl();
        pnl();
        sleep_ms(500);
        print_formatted_message(RED, BOLD, "Do you wish to restart your journey? (y/n): ");
        char restart_choice;
        scanf(" %c", &restart_choice);
        if (restart_choice == 'y' || restart_choice == 'Y')
        {
            return;
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your clarity preserves your sanity.\n");
        print_formatted_message(WHITE, ITALIC, "Your steps are uncertain, as if logic itself fuzzes at the edges. Doubt and certainty become indistinguishable echoes.\nFrom this path, your weapon is scrutiny — but beware: too much seeing can erode the seer.\n");
        hall_of_echoes();
    }
}

void hall_of_echoes()
{
    int wisdom = 0;
    int choice_count = 3;
    int stages[3] = {0, 0, 0};
    while (choice_count > 0)
    {
        clrscr();
        print_ascii_art();
        pnl();
        pnl();
        print_formatted_message(GREEN, BOLD, "##############################\n");
        print_formatted_message(GREEN, BOLD, "##### The Hall of Echoes #####\n");
        print_formatted_message(GREEN, BOLD, "##############################\n\n");
        print_formatted_message(WHITE, ITALIC, "The hall stretches endless; your past thoughts bounce and grow teeth. They repeat you, but not kindly —\n every sentence warps in the echo into accusation or reassurance. Time here folds; a whispered regret may become a lie you once told yourself.\n");
        print_formatted_message(WHITE, ITALIC, "The Hall is vast and empty. The air repeats your every thought—each echo louder, more twisted, and more accusatory than the last.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“In this chamber of mirrored mind, what do you do when your own thoughts turn on you?”\n\n");
        if (stages[0] == 0)
            print_formatted_message(BLUE, BOLD, "Follow the echo — give in to the seduction of certainty it offers\n");
        if (stages[1] == 0)
            print_formatted_message(BLUE, BOLD, "Block your ears — harden against the noise and protect your inner thread\n");
        if (stages[2] == 0)
            print_formatted_message(BLUE, BOLD, "Scream back — reclaim voice, using raw emotion to break the loop\n");

        pnl();
        char choice = choose_path(choice_count);
        if (choice == '1' && stages[0] == 0)
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to follow the echo.\n");
            print_formatted_message(WHITE, ITALIC, "Your younger self steps forward, naïve and accusing in equal measure. The echo offers easy absolution or dangerous nostalgia.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Is the past self a key you should welcome, or a chain you must break?”\n\n");
            print_formatted_message(BLUE, BOLD, "Embrace — integrate past mistakes as the scaffolding of wisdom\nReject — sever ties and attempt a new, unburdened path\n\n");
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
        else if ((stages[1] == 0 && choice == '2' && stages[0] == 0) || (choice == '1' && stages[0] == 1 && stages[1] == 0))
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to block your ears.\n");
            print_formatted_message(WHITE, ITALIC, "You attempt to silence the hall. Silence is not simple absence but a pressure that rearranges thought.\nInternal rhythms press louder when the world is shut out.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you accept this internal cadence as part of you, or do you panic at its insistence?”\n\n");
            print_formatted_message(BLUE, BOLD, "Listen — learn the rhythm and allow it to become guidance\nPanic — fracture under the unbearable mirror of the mind\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You answer the echoes with a raw, human sound that ripples the hall into new harmonics. The choir rearranges, finding patterns you force upon it.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“What response holds the most sanity in the face of overwhelming noise?”\n\n");
            print_formatted_message(BLUE, BOLD, "Keep screaming — let catharsis and continued force shape the environment\nLaugh — use absurdity to unmask the terror the echoes weave\n\n");
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
        clrscr();
        print_ascii_art();
        pnl();
        print_formatted_message(WHITE, ITALIC, "The fog clears. Pestilence approaches, shadow falling over your body, mind, and spirit. He inspects the consequences of your choices across your journey.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“You carry my mark — not of sickness, but wisdom. You have learned that corruption is inevitable, yet its understanding is power.”\n\n");
        print_formatted_message(WHITE, ITALIC, "Your mind is tested, and you emerge stronger.\n");
        pnl();
        print_win_ascii_art();
        pnl();
        exit(0);
    }
    else
    {
        clrscr();
        print_ascii_art();
        pnl();
        print_formatted_message(WHITE, ITALIC, "The fog thickens. Pestilence looms over you, his presence suffocating. He surveys the failures etched into your journey.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“You are but a vessel of my disease — weak, unworthy, and blind. Your ignorance has sealed your fate.”\n\n");
        print_formatted_message(WHITE, ITALIC, "Your mind is tested, and you emerge weaker.\n");
        pnl();
        pnl();
        print_death_ascii_art();
        pnl();
        pnl();
        print_formatted_message(RED, BOLD, "Do you wish to restart your journey? (y/n): ");
        char restart_choice;
        scanf(" %c", &restart_choice);
        if (restart_choice == 'y' || restart_choice == 'Y')
        {
            return;
        }
        else
        {
            exit(0);
        }
    }
}