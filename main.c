#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "output.h"
#include "colors.h"
#include "flesh.h"
#include "faith.h"
#include "thought.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\033[H\033[J")
#endif

int main()
{
    clrscr();
    print_ascii_art();
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, "################################\n");
    print_formatted_message(GREEN, BOLD, "##### The Infested Marshes #####\n");
    print_formatted_message(GREEN, BOLD, "################################\n\n\n");
    print_formatted_message(WHITE, ITALIC, "The air is thick, sickly sweet with rot, and the ground oozes beneath your feet. A figure coalesces from the fever-fog—Pestilence himself.\n");
    print_formatted_message(WHITE, ITALIC, "His voice, a rasping cough, is the first thing you hear in this corrupted land.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“Three paths of decay. Choose your contagion, and see what festers in you.”\n\n");
    print_formatted_message(WHITE, ITALIC, "He gestures, and three swirling clouds of mist form before you. Which form of decay will you embrace to begin your journey?\n\n");
    print_formatted_message(BLUE, BOLD, "Flesh - \"The Rot of That Breathes\"\nFaith - \"The Prayer of the Diseased\"\nThought - \"The Whispering Fog\"\n\n");
    print_formatted_message(YELLOW, BOLD, "Choose your destiny (1, 2 or 3): ");
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
    clrscr();
    print_ascii_art();
    pnl();
    pnl();
    print_formatted_message(GREEN, BOLD, "################################\n");
    print_formatted_message(GREEN, BOLD, "##### The Infested Marshes #####\n");
    print_formatted_message(GREEN, BOLD, "################################\n\n");
    if (choice[0] == '1')
        flesh_path();
    else if (choice[0] == '2')
        faith_path();
    else if (choice[0] == '3')
        thought_path();

    pnl();
    return 0;
}