/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** draw_shapes.c
*/

#include <SFML/Graphics.h>
#include "../../include/framebuffer.h"
#include "../../include/my.h"
#include <stdlib.h>

int draw_line(framebuffer_t *framebuffer, sfVector2i a, sfVector2i b)
{
    for (int x = a.x; x <= b.x; x++)
        for (int y = a.y; y <= b.y; y++)
            my_put_pixel(framebuffer, x, y, sfWhite);
    return (0);
}

void draw_out_circle_cond(framebuffer_t *buffer, sfVector2i pos, int r, int rad)
{
    if (r >= my_power(rad, 2) && r <= my_power(rad, 2) + rad*2)
        my_put_pixel(buffer, pos.x, pos.y, sfWhite);
}

int draw_outline_circle(framebuffer_t *buffer, sfVector2i center, int rad)
{
    int r = 0;
    sfVector2i pos;

    for (int x = center.x - rad; x <= center.x + rad; x++) {
        for (int y = center.y - rad; y <= center.y + rad; y++) {
            r = my_power(x - center.x, 2) + my_power(y - center.y, 2);
            pos.x = x;
            pos.y = y;
            draw_out_circle_cond(buffer, pos, r, rad);
        }
    }
    return (0);
}

void draw_circle_condition(framebuffer_t *buffer, int x, int y, shape_t *c)
{
    int result = my_power(x - c->pos.x, 2) + my_power(y - c->pos.y, 2);

    if (result <= my_power(c->size, 2))
        my_put_pixel(buffer, x, y, c->color);
}

int draw_circle(framebuffer_t *framebuffer, shape_t *c)
{
    int r = 0;
    int max_x = c->pos.x + c->size;
    int max_y = c->pos.y + c->size;

    for (int x = c->pos.x - c->size; x >= 0 && x < max_x && x <= WID; x++)
        for (int y = c->pos.y - c->size; y >= 0 && y < max_y && y <= HEI; y++)
            draw_circle_condition(framebuffer, x, y, c);
    return (0);
}
