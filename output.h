#ifndef OUTPUT_H
#define OUTPUT_H

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\033[H\033[J")
#endif

void print_formatted_message(char color[], char style[], char message[]);
void pnl();
void print_ascii_art();
void print_death_ascii_art();
void print_win_ascii_art();
#endif