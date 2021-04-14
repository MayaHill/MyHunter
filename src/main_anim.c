/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** main_anim.c
*/

#include <my_hunter.h>

int get_difficulty(char **argv, window_t *my_win)
{
    if (my_strcmp(argv[1], "-easy") == 0) {
        my_win->diff = 30.0;
        return (0);
    }
    if (my_strcmp(argv[1], "-normal") == 0) {
        my_win->diff = 20.0;
        return (0);
    }
    if (my_strcmp(argv[1], "-hard") == 0) {
        my_win->diff = 10.0;
        return (0);
    }
    return (1);
}

int main(int ac, char **argv)
{
    window_t my_win;

    if (ac > 2)
        return (print_arg_error(ac - 1));
    if (ac == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return (print_help());
        else if (get_difficulty(argv, &my_win) == 0) {
            my_win = my_create_window(my_win);
            start_game(&my_win);
            return (0);
        } else
            return (print_arg_error(ac - 1));
    }
    my_win = my_create_window(my_win);
    my_win.diff = 15.0;
    my_win.wid = 960;
    my_win.hei = 640;
    start_game(&my_win);
    return (0);
}