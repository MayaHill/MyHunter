/*
** EPITECH PROJECT, 2020
** My_Screensaver
** File description:
** main.c
*/

#include <my_hunter.h>

int print_help(void)
{
    my_printf("Game made by Maya HILL with the CSFML library\n\nSTORY");
    my_printf("\n A wave of 100 asteroids is predicted to hit planet Earth.");
    my_printf("\n Don't let the asteroids reach it!");
    my_printf(" Once Earth is hit 4 times, you lose...\n");
    my_printf(" PS: The number of asteroids increases with time.\n");
    my_printf("\nUSAGE\n ./my_hunter\n");
    my_printf("\nOPTIONS\n -h               print the usage and quit.\n");
    my_printf(" -[difficulty]    scale the difficulty to easy, \
normal or hard (ie: -easy).\n");
    my_printf("\nUSER INTERACTIONS\n");
    my_printf("\n ESCAPEKEY        ");
    my_printf("Close window\n");
    my_printf(" MOUSECLICK       ");
    my_printf("Destroy asteroid\n");
    return (0);
}

int print_arg_error(int n_arg)
{
    my_printf("./my_hunter: bad arguments: %d given but 0 is \
required\n", n_arg);
    my_printf("retry with -h\n");
    return (84);
}
