#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "faith.h"
#include "output.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\033[H\033[J")
#endif

void faith_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You choose the path of the soul, where devotion is tested by suffering, and belief becomes a form of blindness.\nA chorus of desperate, wheezing prayers echoes in your mind.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“If healing one requires the death of ten, is it mercy?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Yes, one life saved is worth it\n2. No, salvation built on suffering is corruption\n3. Depends on the one saved\n\n");
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
        print_formatted_message(RED, BOLD, "Your faith crumbles, leaving you in despair...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the void of disbelief.\n");
        pnl();
        exit(0);
        // TODO: Add a death ascii art here later
        // TODO: Add a delay before exit
        // TODO: Maybe add a restart option later
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your steadfast faith shields you from despair.\n");
        print_formatted_message(WHITE, ITALIC, "The air tastes of ash and false hope, a weight settling on your conscience. Your path now demands sacrifice and difficult moral clarity.\n");
        pilgrim_test();
    }
}

void pilgrim_test()
{
    clrscr();
    print_ascii_art();
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, "##############################\n");
    print_formatted_message(GREEN, BOLD, "##### The Pilgrim's Test #####\n");
    print_formatted_message(GREEN, BOLD, "##############################\n\n");
    print_formatted_message(WHITE, ITALIC, "A pilgrim collapses before you, pustules covering their skin. They gasp out a prayer. You carry one dose of the true cure—enough for them, or for you.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“You carry one cure. Is your life or the purity of your devotion more valuable right now? What do you do?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Give it\n2. Keep it\n3. Leave them\n\n");
    print_formatted_message(YELLOW, BOLD, "Choose your action (1, 2 or 3): ");
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
