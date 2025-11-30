#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define STRIKETHROUGH "\033[9m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep_ms(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
void clrscr()
{
    system("@cls||clear");
}

void print_formatted_message(char color[], char style[], char message[]);
void pnl();
void print_ascii_art();
void print_death_ascii_art();
void print_win_ascii_art();
char choose_path(int choices);
void plagued_village();
void pilgrim_test();
void hall_of_echoes();
void flesh_path();
void faith_path();
void thought_path();

int main()
{
    while (1)
    {
        clrscr();
        print_ascii_art();
        pnl();
        pnl();
        print_formatted_message(GREEN, BOLD, "################################\n");
        print_formatted_message(GREEN, BOLD, "##### The Infested Marshes #####\n");
        print_formatted_message(GREEN, BOLD, "################################\n\n\n");
        print_formatted_message(WHITE, ITALIC, "The marsh waits like a lung gone black with smoke. Each step sinks, and the fog moves as if it breathes.\nFrom that living mist a gaunt figure rises—Pestilence, stitched of cough and shadow. \n");
        print_formatted_message(WHITE, ITALIC, "His presence tastes of metal and old wine. The hush that follows is not silence but the held intake before a scream.\n\n");
        print_formatted_message(RED, BOLD, "Pestilence:\n");
        print_formatted_message(WHITE, BOLD, "\"Three contagions. Each is a truth and a trial. Choose which rot will teach you — for knowledge here is paid in decay.\"\n\n");
        print_formatted_message(WHITE, ITALIC, "He spreads skeletal fingers, and three spirals of mist form, each bearing a different scent:\n iron and earth, incense and ash, and the faint hum of static thought. Which contagion will you take into your bones?\n\n");
        print_formatted_message(BLUE, BOLD, "Flesh - \"The Rot of That Breathes\"\nFaith - \"The Prayer of the Diseased\"\nThought - \"The Whispering Fog\"\n\n");
        char choice = choose_path(3);
        clrscr();
        print_ascii_art();
        pnl();
        pnl();
        print_formatted_message(GREEN, BOLD, "################################\n");
        print_formatted_message(GREEN, BOLD, "##### The Infested Marshes #####\n");
        print_formatted_message(GREEN, BOLD, "################################\n\n");
        if (choice == '1')
            flesh_path();
        else if (choice == '2')
            faith_path();
        else if (choice == '3')
            thought_path();

        pnl();
    }
    return 0;
}

void print_formatted_message(char color[], char style[], char message[])
{
    if (style == NULL)
        style = "";

    sleep_ms(30);
    printf("%s%s%s%s", color, style, message, RESET);
}

void pnl()
{
    printf("\n");
}

void print_ascii_art()
{
    printf(
        "______ _____ _____ _____ _____ _      _____ _   _ _____  _____    ______ ________  ___  ___  _____ _   _ "
        "\n| ___ \\  ___/  ___|_   _|_   _| |    |  ___| \\ | /  __ \\|  ___|   |  _  \\  _  |  \\/  | / _ \\|_   _| \\ | |"
        "\n| |_/ / |__ \\ `--.  | |   | | | |    | |__ |  \\| | /  \\/| |__     | | | | | | | .  . |/ /_\\ \\ | | |  \\| |"
        "\n|  __/|  __| `--. \\ | |   | | | |    |  __|| . ` | |    |  __|    | | | | | | | |\\/| ||  _  | | | | . ` |"
        "\n| |   | |___/\\__/ / | |  _| |_| |____| |___| |\\  | \\__/\\| |___    | |/ /\\ \\_/ / |  | || | | |_| |_| |\\  |"
        "\n\\_|   \\____/\\____/  \\_/  \\___/\\_____/\\____/\\_| \\_/\\____/\\____/    |___/  \\___/\\_|  |_/\\_| |_/\\___/\\_| \\_/"
        "                                                                                                                            \n");
}

void print_death_ascii_art()
{
    printf(
        "______ _____  ___ _____ _   _     _   _   ___   _____     _____ ________  ___ _____ "
        "\n|  _  \\  ___|/ _ \\_   _| | | |   | | | | / _ \\ /  ___|   /  __ \\  _  |  \\/  ||  ___|"
        "\n| | | | |__ / /_\\ \\| | | |_| |   | |_| |/ /_\\ \\\\ `--.    | /  \\/ | | | .  . || |__  "
        "\n| | | |  __||  _  || | |  _  |   |  _  ||  _  | `--. \\   | |   | | | | |\\/| ||  __| "
        "\n| |/ /| |___| | | || | | | | |   | | | || | | |/\\__/ /   | \\__/\\ \\_/ / |  | || |___ "
        "\n|___/ \\____/\\_| |_/\\_/ \\_| |_/   \\_| |_/\\_| |_/\\____/     \\____/\\___/\\_|  |_/\\____/ "
        "\n                                                                                    "

    );
}

void print_win_ascii_art()
{
    printf(
        "__   _______ _   _     _    _ _____ _   _ "
        "\n\\ \\ / /  _  | | | |   | |  | |_   _| \\ | |"
        "\n \\ V /| | | | | | |   | |  | | | | |  \\| |"
        "\n  \\ / | | | | | | |   | |/\\| | | | | . ` |"
        "\n  | | \\ \\_/ / |_| |   \\  /\\  /_| |_| |\\  |"
        "\n  \\_/  \\___/ \\___/     \\/  \\/ \\___/\\_| \\_/"
        "\n                                          "

    );
}

char choose_path(int choices)
{
    if (choices == 3)
    {
        print_formatted_message(YELLOW, BOLD, "Choose one option (1, 2 or 3): ");
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
        return choice[0];
    }
    else if (choices == 2)
    {
        print_formatted_message(YELLOW, BOLD, "Choose one option (1 or 2): ");
        char choice[10];
        scanf("%s", choice);
        while (1)
        {
            if ((choice[0] == '1' || choice[0] == '2') && choice[1] == '\0')
            {
                break;
            }
            else
            {
                pnl();
                print_formatted_message(RED, NULL, "Ignorant fool! Choose again (1 or 2): ");
                scanf("%s", choice);
            }
        }
        return choice[0];
    }
    else if (choices == 1)
    {
        print_formatted_message(YELLOW, BOLD, "Choose one option (1): ");
        char choice[10];
        scanf("%s", choice);
        while (1)
        {
            if (choice[0] == '1' && choice[1] == '\0')
            {
                break;
            }
            else
            {
                pnl();
                print_formatted_message(RED, NULL, "Ignorant fool! Choose again (1): ");
                scanf("%s", choice);
            }
        }
        return choice[0];
    }
}

void flesh_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You step toward a fog that smells of damp soil and fever. The heat of disease presses at your skin, a pressure like a thousand whispered ailments.\nYour own heartbeat becomes a metronome counting down to erosion — not only of body but of what it anchors.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "\"When flesh unravels, what is the first casualty — wound, weakness, or will?\"\n\n");
    print_formatted_message(BLUE, BOLD, "The wound itself — the immediate, visible break\nThe infection within — the slow, unseen spread\nThe fear of dying — the mind that surrenders first\n\n");
    char choice = choose_path(3);
    if (choice != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your flesh trembles and decays rapidly...\n");
        print_formatted_message(WHITE, ITALIC, "You have succumbed to the plague of your own making.\n");
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
        print_formatted_message(WHITE, BOLD, "\"The village is dying. The choices before you are visceral and blunt. How do you respond to a community unraveling under infection?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"The child lives, but the contagion sleeps within you now. Do you press onward bearing this burden?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Do you stay to help organize the ashes — to name the dead and give them what dignity remains — or do you flee the scenes you helped create?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"In the quiet behind the sealed gate, which feeling anchors you?\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You carry my mark — not of sickness, but wisdom. You have learned that corruption is inevitable, yet its understanding is power.\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You are but a vessel of my disease — weak, unworthy, and blind. Your ignorance has sealed your fate.\"\n\n");
        print_formatted_message(WHITE, ITALIC, "Your flesh is tested, and you emerge weaker.\n");
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

void faith_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You follow a column of cold light wherein prayers hang like moths. Devotion here feels heavy—every whispered supplication weighs like a coin in a closed palm.\nThe air tastes of burnt offerings and hope that has been ground fine by despair.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "\"When salvation requires sacrifice, does mercy remain mercy or become currency?\"\n\n");
    print_formatted_message(BLUE, BOLD, "Yes, one life saved is worth many lost — a necessary calculus\nNo, salvation spun from suffering is corrosion of the sacred\nDepends on the one saved — judgement must be contextual\n\n");
    char choice = choose_path(3);
    if (choice != '2')
    {
        pnl();
        print_formatted_message(RED, BOLD, "Your faith crumbles, leaving you in despair...\n");
        print_formatted_message(WHITE, ITALIC, "You are lost in the void of disbelief.\n");
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
        print_formatted_message(WHITE, BOLD, "\"You carry one cure. Is your life a commodity for devotion, or does duty demand a harder choice?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Can you endure the cost your compassion has demanded? Will your faith sustain you beneath this new weight?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Do you let shame fester quietly, or do you carry it as a lesson that sharpens you?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Do you offer a final kindness even in absence — a whispered prayer or an indifferent step?\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You carry my mark — not of sickness, but wisdom. You have learned that corruption is inevitable, yet its understanding is power.\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You are but a vessel of my disease — weak, unworthy, and blind. Your ignorance has sealed your fate.\"\n\n");
        print_formatted_message(WHITE, ITALIC, "Your faith is tested, and you emerge weaker.\n");
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

void thought_path()
{
    pnl();
    print_formatted_message(WHITE, ITALIC, "You step into a fog that murmurs in languages you know and those you've never heard. Ideas feel like viruses here —\n contagious, seductive, altering the shape of questions until they bite.\nThe air tastes like old libraries and the metallic tang of revelation.\n\n");
    print_formatted_message(RED, BOLD, "Pestilence:\n");
    print_formatted_message(WHITE, BOLD, "\"Does knowing alter the knower, or merely reveal what already festers within?\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"In this chamber of mirrored mind, what do you do when your own thoughts turn on you?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Is the past self a key you should welcome, or a chain you must break?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"Do you accept this internal cadence as part of you, or do you panic at its insistence?\"\n\n");
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
            print_formatted_message(WHITE, BOLD, "\"What response holds the most sanity in the face of overwhelming noise?\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You carry my mark — not of sickness, but wisdom. You have learned that corruption is inevitable, yet its understanding is power.\"\n\n");
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
        print_formatted_message(WHITE, BOLD, "\"You are but a vessel of my disease — weak, unworthy, and blind. Your ignorance has sealed your fate.\"\n\n");
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
