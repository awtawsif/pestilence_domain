#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "flesh.h"
#include "output.h"
#include "choose.h"

void flesh_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You choose the path of the body, the immediate, sickening truth of physical corruption.\nThe air grows heavier, and your own skin begins to prickle with fever.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“When flesh fails, what kills first?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. The wound itself\n2. The infection within\n3. The fear of dying\n\n");
    char choice = choose_path(3);
    if (choice != '2')
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
    print_formatted_message(WHITE, ITALIC, "You arrive at a village shrouded in mist, the air thick with the stench of decay. \nThe villagers cough and bleed; eyes pleading as they crawl toward you.\n");
    print_formatted_message(WHITE, ITALIC, "They are beyond saving, yet their suffering is a raw, painful plea.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“The village is dying. How do you handle the infected populace?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Heal the child\n");
    print_formatted_message(BLUE, BOLD, "2. Burn the sick\n");
    print_formatted_message(BLUE, BOLD, "3. Seal the gates\n\n");
    char choice = choose_path(3);
    if (choice == '1')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to heal the child.\n");
        print_formatted_message(WHITE, ITALIC, "The child you saved coughs violently, transferring some of the infection to you. Your veins pulse with rot.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“The child lives. You cough blood, the infection transferred. Do you have the strength to continue, knowing the rot is now fully in you?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Yes, I can fight it\n2. No, I cannot bear it\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
    else if (choice == '2')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to burn the sick.\n");
        print_formatted_message(WHITE, ITALIC, "The sick are consumed in purifying flames, leaving only smoke and ashes.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“Do you stay to help organize the ashes?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Yes, I will\n2. No, I will leave\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to seal the gates.\n");
        print_formatted_message(WHITE, ITALIC, "You close off the village to prevent the spread, leaving cries behind.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“In this quiet, what feeling is strongest?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Fear\n2. Guilt\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
}