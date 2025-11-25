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
    print_formatted_message(WHITE, ITALIC, "You step toward a fog that smells of damp soil and fever. The heat of disease presses at your skin, a pressure like a thousand whispered ailments.\nYour own heartbeat becomes a metronome counting down to erosion — not only of body but of what it anchors.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "“When flesh unravels, what is the first casualty — wound, weakness, or will?”\n\n");
    print_formatted_message(BLUE, BOLD, "The wound itself — the immediate, visible break\nThe infection within — the slow, unseen spread\nThe fear of dying — the mind that surrenders first\n\n");
    char choice = choose_path(3);
    if (choice != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your flesh trembles and decays rapidly...\n");
        print_formatted_message(WHITE, ITALIC, "You have succumbed to the plague of your own making.\n");
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
        print_formatted_message(WHITE, ITALIC, "Your choice spares you from immediate decay.\n");
        print_formatted_message(WHITE, ITALIC, "A shiver crawls beneath your ribs. Your reflection in a puddle distorts into patched skin and hollows; the world feels tactile and unforgiving.\nYou have begun the lesson of bodies that betray, and every step forward will be measured against the cost of survival.\n");
        plagued_village();
    }
}

void plagued_village()
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
        print_formatted_message(GREEN, BOLD, "###############################\n");
        print_formatted_message(GREEN, BOLD, "##### The Plagued Village #####\n");
        print_formatted_message(GREEN, BOLD, "###############################\n\n");
        print_formatted_message(WHITE, ITALIC, "The village is a chorus of broken breaths. Children thread between shrouded adults; the sick press palms to doors as if touch could tether them to life.\nThe stench of rot hides behind every curtain, yet some faces still search your eyes for rescue.\n");
        print_formatted_message(WHITE, ITALIC, "They are beyond saving, yet their suffering is a raw, painful plea.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "“The village is dying. The choices before you are visceral and blunt. How do you respond to a community unraveling under infection?”\n\n");
        if (stages[0] == 0)
            print_formatted_message(BLUE, BOLD, "Heal the child — pull a single life back from the edge, but at cost to your strength\n");
        if (stages[1] == 0)
            print_formatted_message(BLUE, BOLD, "Burn the sick — end the bodies to starve the disease, sacrificing souls to save hosts\n");
        if (stages[2] == 0)
            print_formatted_message(BLUE, BOLD, "Seal the gates — isolate the blight, condemning those inside to a slow extinguishing\n");

        pnl();
        char choice = choose_path(choice_count);
        if (choice == '1' && stages[0] == 0)
        {
            pnl();
            print_formatted_message(WHITE, ITALIC, "You have chosen to heal the child.\n");
            print_formatted_message(WHITE, ITALIC, "The child you saved coughs wetly into your palm; the infection has leapt in recompense. Your veins hum with cold fire.\nTo move forward you must accept that compassion can wound the compassionate.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“The child lives, but the contagion sleeps within you now. Do you press onward bearing this burden?”\n\n");
            print_formatted_message(BLUE, BOLD, "Yes — carry the rot as a badge and press on\nNo — surrender to care or to the rot and stop here\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You have chosen to burn the sick.\n");
            print_formatted_message(WHITE, ITALIC, "Flames take the sick with the crack and roar of decisive violence. The air fills with ashes and lost names.\nIn the wake of the blaze, only bones and scorched earth remain.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“Do you stay to help organize the ashes — to name the dead and give them what dignity remains — or do you flee the scenes you helped create?”\n\n");
            print_formatted_message(BLUE, BOLD, "Stay to help — bear witness, catalog sorrow, try to restore human order\nFlee — escape the weight, sparing yourself the stain of remembrance\n\n");
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
            print_formatted_message(WHITE, ITALIC, "You have chosen to seal the gates.\n");
            print_formatted_message(WHITE, ITALIC, "You shut the bolts on the village, the hinges whining like small graves closing. The lamplight inside wanes; through cracks you hear muffled pleading.\nThe world beyond keeps breathing, but you have left a pocket of silence to grow.\n\n");
            print_formatted_message(RED, BOLD, "Pestilence:\n");
            print_formatted_message(WHITE, BOLD, "“In the quiet behind the sealed gate, which feeling anchors you?”\n\n");
            print_formatted_message(BLUE, BOLD, "Relief — the pragmatic cold calculus of safety\nGuilt — the long, corrosive ache of chosen exile\n\n");
            choice = choose_path(2);
            if (choice == '2')
            {
                wisdom += 1;
                stages[2] = 1;
            }
            else if (choice == '1')
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
        print_formatted_message(WHITE, ITALIC, "Your flesh is tested, and you emerge stronger.\n");
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
        print_formatted_message(WHITE, ITALIC, "Your flesh is tested, and you emerge weaker.\n");
        pnl();
        print_death_ascii_art();
        pnl();
        exit(0);
    }
}