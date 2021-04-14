/*
** EPITECH PROJECT, 2020
** My_Hunter.c
** File description:
** create_components.c
*/

#include <my_hunter.h>

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {WID, HEI, 32};
    char *name = "My Hunter";

    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void reset_framebuffer_to_color(framebuffer_t *framebuffer, sfColor color)
{
    for (int x = 0; x < WID; x++)
        for (int y = 0; y < HEI; y++)
            my_put_pixel(framebuffer, x, y, color);
}

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font)
{
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 16);
    sfText_setPosition(text, pos);
    return (text);

}