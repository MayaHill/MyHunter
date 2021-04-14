/*
** EPITECH PROJECT, 2020
** IntroCSFML
** File description:
** framebuffer.h
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>

static int WID = 960;
static int HEI = 640;

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

typedef struct shape_s {
    sfVector2i pos;
    int size;
    sfColor color;
} shape_t;

typedef struct window_s {
    sfRenderWindow *window;
    framebuffer_t *buffer;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfText *text;
    sfText *s_text;
    int lives;
    int score;
    float diff;
    int wid;
    int hei;
} window_t;

typedef struct back_s {
    sfTexture *texture;
    sfSprite *sprite;
} back_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel(framebuffer_t *b, unsigned int x, unsigned int y, sfColor);

void my_draw_square (framebuffer_t *, sfVector2u, unsigned int, sfColor);

int draw_outline_circle(framebuffer_t *buff, sfVector2i center, int radius);

int draw_circle(framebuffer_t *buff, shape_t *circle);

int draw_line(framebuffer_t *buff, sfVector2i point_a, sfVector2i point_b);

void draw_rect(framebuffer_t *buffer, shape_t *rect1);

#endif /* FRAMEBUFFER_H_ */