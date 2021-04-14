/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** my_screensaver.h
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "framebuffer.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "my_printf.h"

typedef struct asteroid_s {
    sfVector2f pos;
    sfVector2f velocity;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfBool collided;
} asteroid_t;

typedef struct obj_array_s {
    asteroid_t asteroids[100];
    int size;
} obj_array_t;

typedef struct objects_s {
    sfTexture *earth_t;
    sfSprite *earth_s;
    sfVector2f earth_pos;
    sfTexture *explosion_t;
    sfSprite *explosion_s;
    sfVector2f explosion_pos;
} objects_t;

obj_array_t create_asteroids_array(void);

obj_array_t add_asteroid(sfRenderWindow *win, obj_array_t objs, char *path);

obj_array_t update_asteroids(window_t *win, obj_array_t asteroids_array);

void get_updated_pos(window_t *win, obj_array_t *obj_array, int index);

void new_asteroids_pos(obj_array_t *obj_array, int index);

void is_colliding(window_t *win, obj_array_t *obj_array, int index);

void display_asteroids(sfRenderWindow *window, obj_array_t *asteroids_array);

void destroy_asteroids(obj_array_t asteroids_array);

int print_nbr_error();

int print_help();

int print_anim();

int print_arg_error(int n_arg);

void start_game(window_t *win);

void clear_game(window_t *my_win, obj_array_t obj_array);

sfRenderWindow *create_window(void);

window_t my_create_window(window_t my_win);

void reset_framebuffer_to_color(framebuffer_t *framebuffer, sfColor color);

void analyse_events(sfRenderWindow *window, sfBool *can_start);

int rand_nbr(int lower, int upper);

void explode(obj_array_t *obj_array, int index);

void mouse_event(window_t *win, obj_array_t *obj_array);

float get_seconds(sfClock *clock);

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font);

void game_over(window_t *win);

void game_won(window_t *win);

void parallax_loop(window_t *win, sfSprite *earth);

obj_array_t draw_loop(window_t *win, obj_array_t objs, sfSprite *earth_s);

obj_array_t game_loop(window_t *, obj_array_t, sfSprite *, sfClock *);

obj_array_t can_add_asteroids(window_t *win, obj_array_t objs);

void my_draw_on_window_loop(window_t *win, obj_array_t objs, sfSprite *earth_s);

#endif /* !MY_HUNTER_H_ */