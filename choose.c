#include <stdio.h>
#include "colors.h"
#include "output.h"
#include "choose.h"

char choose_path(int choices) {
    if (choices == 3)
    {
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
        return choice[0];
    }
    else if (choices == 2)
    {
        print_formatted_message(YELLOW, BOLD, "Choose your destiny (1 or 2): ");
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
}
