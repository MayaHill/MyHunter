/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** anim1-essentials.c
*/

#include <my_hunter.h>

void analyse_events(sfRenderWindow *window, sfBool *can_start)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeySpace && *can_start == sfFalse)
            *can_start = sfTrue;
    }
}

int rand_nbr(int lower, int upper)
{
    int nbr = (rand() % (upper - lower + 1)) + lower;

    return (nbr);
}

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}

void game_over(window_t *win)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfText_setString(win->text, "GAME OVER");
    sfText_setCharacterSize(win->text, 32);
    sfText_setPosition(win->text, (sfVector2f){WID/2 - 96, HEI/2});
    sfRenderWindow_drawText(win->window, win->text, NULL);
    sfRenderWindow_display(win->window);
}

void game_won(window_t *win)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfText_setString(win->text, "                       CONGRATULATIONS\n\n \
    You successfully repelled all 100 asteroids!");
    sfText_setCharacterSize(win->text, 20);
    sfText_setPosition(win->text, (sfVector2f){WID/6, HEI/2});
    sfRenderWindow_drawText(win->window, win->text, NULL);
    sfRenderWindow_display(win->window);
}