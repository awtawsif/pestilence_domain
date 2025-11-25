#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "output.h"
#include "colors.h"
#include "flesh.h"
#include "faith.h"
#include "thought.h"
#include "choose.h"

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
        print_formatted_message(WHITE, BOLD, "“Three contagions. Each is a truth and a trial. Choose which rot will teach you — for knowledge here is paid in decay.”\n\n");
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