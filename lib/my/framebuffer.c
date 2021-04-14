/*
** EPITECH PROJECT, 2020
** IntroCSFML
** File description:
** framebuffer.c
*/

#include <SFML/Graphics.h>
#include "../../include/framebuffer.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame;

    frame = malloc(sizeof(framebuffer_t));
    frame->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    frame->width = width;
    frame->height = height;
    return (frame);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
    return;
}

void my_put_pixel(framebuffer_t *b, unsigned int x, unsigned int y, sfColor c)
{
    int pos = (b->width * y + x) * 4;

    b->pixels[pos + 0] = c.r;
    b->pixels[pos + 1] = c.g;
    b->pixels[pos + 2] = c.b;
    b->pixels[pos + 3] = c.a;
    return;
}

void my_draw_square(framebuffer_t *b, sfVector2u p, unsigned int s, sfColor c)
{
    for (int x = p.x; x < (p.x + s); x++)
        for (int y = p.y; y < (p.y + s); y++)
            my_put_pixel(b, x, y, c);
}

void draw_rect(framebuffer_t *buffer, shape_t *rect1)
{
    for (int x = rect1->pos.x; x < rect1->pos.x + 80; x++)
        for (int y = rect1->pos.y; y < rect1->pos.y + 60; y++)
            my_put_pixel(buffer, x, y, rect1->color);
}