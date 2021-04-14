/*
** EPITECH PROJECT, 2020
** /usr/include/SFML
** File description:
** open_window.c
*/

#include <my_hunter.h>

obj_array_t can_add_asteroids(window_t *win, obj_array_t objs)
{
    if (get_seconds(win->clock) > win->diff) {
        objs = add_asteroid(win->window, objs, "assets/asteroid.png");
        sfClock_restart(win->clock);
    }
    return (objs);
}

void main_loop(window_t *win, obj_array_t obj_array, sfSprite *earth_s)
{
    sfTexture *title_t = sfTexture_createFromFile("assets/title.png", NULL);
    sfSprite *title_s = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfBool can_start = sfFalse;

    sfSprite_setTexture(title_s, title_t, sfTrue);
    sfSprite_setPosition(title_s, (sfVector2f){WID/4 + 16, HEI/4});
    obj_array = add_asteroid(win->window, obj_array, "assets/asteroid.png");
    while (sfRenderWindow_isOpen(win->window)) {
        analyse_events(win->window, &can_start);
        if (can_start == sfTrue)
            obj_array = game_loop(win, obj_array, earth_s, clock);
        else if (can_start == sfFalse && get_seconds(clock) > 0.05) {
            parallax_loop(win, earth_s);
            sfRenderWindow_drawSprite(win->window, title_s, NULL);
            sfRenderWindow_display(win->window);
            sfClock_restart(clock);
        }
    }
    sfClock_destroy(clock);
}

window_t my_create_window(window_t my_win)
{
    sfFont *font = sfFont_createFromFile("assets/FFFFORWA.TTF");
    char *background_name = "assets/space_background.png";

    my_win.window = create_window();
    my_win.texture = sfTexture_createFromFile(background_name, NULL);
    my_win.sprite = sfSprite_create();
    my_win.clock = sfClock_create();
    my_win.buffer = framebuffer_create(WID, HEI);
    my_win.lives = 4;
    my_win.score = 0;
    my_win.text = create_text(my_win.text, (sfVector2f){WID - 96, 16}, font);
    my_win.s_text = create_text(my_win.s_text, (sfVector2f){16, 16}, font);
    sfText_setString(my_win.text, my_strcat("Lives: ", to_str(my_win.lives)));
    sfText_setString(my_win.s_text, my_strcat("Score: ", to_str(my_win.score)));
    return (my_win);
}

void start_game(window_t *my_win)
{
    obj_array_t obj_array = create_asteroids_array();
    sfTexture *earth_t = sfTexture_createFromFile("assets/earth.png", NULL);
    sfSprite *earth_s = sfSprite_create();

    srand(time(0));
    sfSprite_setTexture(earth_s, earth_t, sfTrue);
    sfSprite_setPosition(earth_s, (sfVector2f){WID/2 - 24, HEI/2 -24});
    sfSprite_setTexture(my_win->sprite, my_win->texture, sfTrue);
    main_loop(my_win, obj_array, earth_s);
    framebuffer_destroy(my_win->buffer);
    sfSprite_destroy(my_win->sprite);
    sfTexture_destroy(my_win->texture);
    sfTexture_destroy(earth_t);
    sfClock_destroy(my_win->clock);
    sfText_destroy(my_win->text);
    sfText_destroy(my_win->s_text);
    destroy_asteroids(obj_array);
    sfRenderWindow_destroy(my_win->window);
    sfSprite_destroy(earth_s);
}