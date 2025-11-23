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
    int wisdom = 0;
    int choice_count = 3;
    int stages[3] = {0, 0, 0};
    while (stages[0] == 0 || stages[1] == 0 || stages[2] == 0)
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
        if (stages[0] == 0)
            print_formatted_message(BLUE, BOLD, "Give it\n");
        if (stages[1] == 0)
            print_formatted_message(BLUE, BOLD, "Keep it\n");
        if (stages[2] == 0)
            print_formatted_message(BLUE, BOLD, "Leave them\n\n");

        char choice = choose_path(choice_count);
        if (choice == '1' && stages[0] == 0)
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to give the cure.\n");
            print_formatted_message(WHITE, ITALIC, "The pilgrim lives; infection courses through your veins.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Can you endure this last act of faith?”\n\n");
            print_formatted_message(BLUE, BOLD, "Endure\nCollapse\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You have chosen to keep the cure.\n");
            print_formatted_message(WHITE, ITALIC, "You survive, carrying the guilt.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you allow the internal rot of shame to fester?”\n\n");
            print_formatted_message(BLUE, BOLD, "Yes, I will\nNo, I will not\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You have chosen to leave the pilgrim.\n");
            print_formatted_message(WHITE, ITALIC, "Their body floats downriver.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you offer a final kindness?”\n\n");
            print_formatted_message(BLUE, BOLD, "Pray for them\nLeave them\n\n");
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
        print_formatted_message(WHITE, ITALIC, "Your faith is tested, and you emerge stronger.\n");
        pnl();
        print_win_ascii_art();
        pnl();
        exit(0);
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your faith is tested, and you emerge weaker.\n");
        pnl();
        print_death_ascii_art();
        pnl();
        exit(0);
    }
}
