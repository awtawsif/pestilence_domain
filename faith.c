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
    print_formatted_message(WHITE, ITALIC, "You follow a column of cold light wherein prayers hang like moths. Devotion here feels heavy—every whispered supplication weighs like a coin in a closed palm.\nThe air tastes of burnt offerings and hope that has been ground fine by despair.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“When salvation requires sacrifice, does mercy remain mercy or become currency?”\n\n");
    print_formatted_message(BLUE, BOLD, "Yes, one life saved is worth many lost — a necessary calculus\nNo, salvation spun from suffering is corrosion of the sacred\nDepends on the one saved — judgement must be contextual\n\n");
    char choice = choose_path(3);
    if (choice != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your faith crumbles, leaving you in despair...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the void of disbelief.\n");
        pnl();
        print_death_ascii_art();
        pnl();
        sleep_ms(500);
        exit(0);
        // TODO: Maybe add a restart option later
    }
    else
    {
        pnl();
        print_formatted_message(WHITE, ITALIC, "Your steadfast faith shields you from despair.\n");
        print_formatted_message(WHITE, ITALIC, "The warmth of faith sits uneasily beneath your ribs like a candle melting on a book of law. Your path will demand choices that mark you: altar or ash, compassion or calculation.\nThe world will test whether conviction can withstand contagion.\n");
        pilgrim_test();
    }
}

void pilgrim_test()
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
        print_formatted_message(GREEN, BOLD, "##### The Pilgrim's Test #####\n");
        print_formatted_message(GREEN, BOLD, "##############################\n\n");
        print_formatted_message(WHITE, ITALIC, "A pilgrim staggers to their knees, fever and faith braided on their lips. Their hands clutch a rosary beaded with blood and hope.\nYou possess a single vial — the true cure, potent and finite. Its presence turns morality into mechanics: who will wield mercy, and at what price?\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“You carry one cure. Is your life a commodity for devotion, or does duty demand a harder choice?”\n\n");
        if (stages[0] == 0)
            print_formatted_message(BLUE, BOLD, "Give it — act as sacrament and save another, accepting the wound you earn\n");
        if (stages[1] == 0)
            print_formatted_message(BLUE, BOLD, "Keep it — preserve your chance to continue the work, or to survive yourself\n");
        if (stages[2] == 0)
            print_formatted_message(BLUE, BOLD, "Leave them — abstain from interference, allowing fate to flow as it will\n");

        pnl();
        char choice = choose_path(choice_count);
        if (choice == '1' && stages[0] == 0)
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to give the cure.\n");
            print_formatted_message(WHITE, ITALIC, "The pilgrim clutches life anew; their thanks is a thin, pleading sound. The cure's price is etched into your flesh — infection or exhaustion,\n a mark that your mercy had a toll.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Can you endure the cost your compassion has demanded? Will your faith sustain you beneath this new weight?”\n\n");
            print_formatted_message(BLUE, BOLD, "Endure — bend but do not break under the cross of consequence\nCollapse — admit that even saints can snap when burdened\n\n");
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
        else if ((stages[1] == 0 && choice == '2' && stages[0] == 0) || (stages[1] == 0 && choice == '1' && stages[0] == 1))
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to keep the cure.\n");
            print_formatted_message(WHITE, ITALIC, "You keep the vial as a promise to yourself: a future safeguard, a bargaining chip against fate. The pilgrim dies or survives by some other hand.\nGuilt nests in small, invasive ways.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you let shame fester quietly, or do you carry it as a lesson that sharpens you?”\n\n");
            print_formatted_message(BLUE, BOLD, "Forget — bury the memory and continue functioning\nRemember — let the memory refine your choices and humble you\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You turn away as the pilgrim’s body is borne by the river. The current takes what you will not touch. A small ripple spreads outward —\n your inaction has a geometry.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you offer a final kindness even in absence — a whispered prayer or an indifferent step?”\n\n");
            print_formatted_message(BLUE, BOLD, "Pray — bestow a private benediction and meet your inaction with ritual\nIgnore — hold to detachment as a doctrine of survival\n\n");
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
        print_formatted_message(WHITE, ITALIC, "Your faith is tested, and you emerge stronger.\n");
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
        print_formatted_message(WHITE, ITALIC, "Your faith is tested, and you emerge weaker.\n");
        pnl();
        print_death_ascii_art();
        pnl();
        exit(0);
    }
}
