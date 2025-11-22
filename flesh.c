#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "flesh.h"
#include "output.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\033[H\033[J")
#endif

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
        print_formatted_message(WHITE, ITALIC, "Your choice spares you from immediate decay.\n");
        print_formatted_message(WHITE, ITALIC, "You feel a subtle, painful shift in your bones, a silent acknowledgement of the unseen enemy.\nThe path ahead is now a labyrinth of physical distress.\n");
        plagued_village();
    }
}

void plagued_village()
{
    clrscr();
    print_ascii_art();
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, "###############################\n");
    print_formatted_message(GREEN, BOLD, "##### The Plagued Village #####\n");
    print_formatted_message(GREEN, BOLD, "###############################\n\n");
    print_formatted_message(WHITE, ITALIC, "You arrive at a village shrouded in mist, the air thick with the stench of decay. \nThe villagers cough and bleed; eyes pleading as they crawl toward you\n");
    print_formatted_message(WHITE, ITALIC, ". They are beyond saving, yet their suffering is a raw, painful plea.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“The village is dying. How do you handle the infected populace?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Heal the child\n2. Burn the sick\n3. Seal the gates\n\n");
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
    if (choice[0] == '1')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to heal the child.\n");
        pnl();
        exit(0);
    }
    else if (choice[0] == '2')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to burn the sick.\n");
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to seal the gates.\n");
        pnl();
        exit(0);
    }
}