#include <stdio.h>
#include "output.h"

#define RESET "\033[0m"
void print_formatted_message(char color[], char style[], char message[])
{
    if (style == NULL)
        style = "";

    printf("%s%s%s%s", color, style, message, RESET);
}

void pnl()
{
    printf("\n");
}