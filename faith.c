#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "faith.h"
#include "output.h"
#include "choose.h"

void faith_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You choose the path of the soul, where devotion is tested by suffering, and belief becomes a form of blindness.\nA chorus of desperate, wheezing prayers echoes in your mind.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“If healing one requires the death of ten, is it mercy?”\n\n");
    print_formatted_message(BLUE, BOLD, "1. Yes, one life saved is worth it\n2. No, salvation built on suffering is corruption\n3. Depends on the one saved\n\n");
    char choice = choose_path(3);
    if (choice != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your faith crumbles, leaving you in despair...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the void of disbelief.\n");
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
    print_formatted_message(BLUE, BOLD, "1. Give it\n");
    print_formatted_message(BLUE, BOLD, "2. Keep it\n");
    print_formatted_message(BLUE, BOLD, "3. Leave them\n\n");
    char choice = choose_path(3);
    if (choice == '1')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to give the cure.\n");
        print_formatted_message(WHITE, ITALIC, "The pilgrim lives; infection courses through your veins.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“Can you endure this last act of faith?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Endure\n2. Collapse\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
    else if (choice == '2')
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to keep the cure.\n");
        print_formatted_message(WHITE, ITALIC, "You survive, carrying the guilt.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“Do you allow the internal rot of shame to fester?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Yes, I will\n2. No, I will not\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "You have chosen to leave the pilgrim.\n");
        print_formatted_message(WHITE, ITALIC, "Their body floats downriver.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“Do you offer a final kindness?”\n\n");
        print_formatted_message(BLUE, BOLD, "1. Pray for them\n2. Leave them\n\n");
        choice = choose_path(2);
        pnl();
        exit(0);
    }
}
