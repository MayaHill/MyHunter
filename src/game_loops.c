/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** game_loops.c
*/

#include <my_hunter.h>

void parallax_loop(window_t *win, sfSprite *earth)
{
    sfVector2f pos = sfSprite_getPosition(win->sprite);
    pos.x -= 2;
    if (pos.x < -WID)
        pos.x = 0;
    sfRenderWindow_clear(win->window, sfBlack);
    sfSprite_setPosition(win->sprite, pos);
    sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
    sfRenderWindow_drawSprite(win->window, earth, NULL);
}

void my_draw_on_window_loop(window_t *win, obj_array_t objs, sfSprite *earth_s)
{
    parallax_loop(win, earth_s);
    display_asteroids(win->window, &objs);
    sfText_setString(win->text, my_strcat("Lives: ", to_str(win->lives)));
    sfText_setString(win->s_text, my_strcat("Score: ", to_str(win->score)));
    sfRenderWindow_drawText(win->window, win->text, NULL);
    sfRenderWindow_drawText(win->window, win->s_text, NULL);
    sfRenderWindow_display(win->window);
}

obj_array_t draw_loop(window_t *win, obj_array_t objs, sfSprite *earth_s)
{
    objs = can_add_asteroids(win, objs);
    objs = update_asteroids(win, objs);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        mouse_event(win, &objs);
    return (objs);
}

obj_array_t game_loop(window_t *w, obj_array_t objs, sfSprite *earth, \
sfClock *clock)
{
    if (w->score >= 100)
        game_won(w);
    else if (w->lives <= 0)
        game_over(w);
    if (w->score < 100 && w->lives > 0) {
        if (get_seconds(clock) > 0.05)
            objs = draw_loop(w, objs, earth);
        my_draw_on_window_loop(w, objs, earth);
    }
    return (objs);
}