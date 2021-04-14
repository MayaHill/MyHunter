/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** explosion_anim.c
*/

#include <my_hunter.h>

void check_is_touching(window_t *w, sfVector2i mouse, obj_array_t *objs, int i)
{
    sfVector2f asteroid = objs->asteroids[i].pos;

    if (objs->asteroids[i].collided != sfTrue \
&& mouse.x >= asteroid.x + 10 && mouse.x < asteroid.x + 50) {
            if (mouse.y >= asteroid.y + 10 && mouse.y < asteroid.y + 50) {
                objs->asteroids[i].collided = sfTrue;
                w->score += 1;
            }
        }
}

void mouse_event(window_t *win, obj_array_t *obj_array)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);

    for (int index = 0; index < obj_array->size; index++)
        check_is_touching(win, mouse, obj_array, index);
}