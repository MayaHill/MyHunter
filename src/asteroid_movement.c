/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** asteroid_movement.c
*/

#include <my_hunter.h>

obj_array_t update_asteroids(window_t *win, obj_array_t obj_array)
{
    for (int index = 0; index < obj_array.size; index++) {
        if (get_seconds(obj_array.asteroids[index].clock) > 0.02) {
            get_updated_pos(win, &obj_array, index);
            sfClock_restart(obj_array.asteroids[index].clock);
        }
    }
    return (obj_array);
}

void get_updated_pos(window_t *win, obj_array_t *obj_array, int index)
{
    sfVector2f new_pos;
    sfIntRect rect = obj_array->asteroids[index].rect;
    sfBool collided = obj_array->asteroids[index].collided;

    new_pos = obj_array->asteroids[index].pos;
    new_pos.x += obj_array->asteroids[index].velocity.x;
    new_pos.y += obj_array->asteroids[index].velocity.y;
    obj_array->asteroids[index].pos = new_pos;
    sfSprite_setPosition(obj_array->asteroids[index].sprite, new_pos);
    is_colliding(win, obj_array, index);
    if (new_pos.x > WID || new_pos.x < 0 || new_pos.y > HEI || new_pos.y < 0) {
        new_asteroids_pos(obj_array, index);
    }
    if (collided == sfTrue && rect.left < 512) {
        obj_array->asteroids[index].rect.left += 64;
        sfSprite_setTextureRect(obj_array->asteroids[index].sprite, rect);
    } else if (rect.left >= 512)
        obj_array->asteroids[index].pos = (sfVector2f){-50, -50};
}

void is_colliding(window_t *win, obj_array_t *obj_array, int index)
{
    sfVector2f earth = (sfVector2f){WID / 2 - 24, HEI / 2 - 24};
    sfVector2f ast = obj_array->asteroids[index].pos;
    sfBool collided = obj_array->asteroids[index].collided;

    if (collided == sfFalse && ast.x > earth.x - 24 && ast.x < earth.x + 24) {
        if (ast.y > earth.y - 24 && ast.y < earth.y + 24) {
            obj_array->asteroids[index].collided = sfTrue;
            win->lives -= 1;
        }
    }
}

void new_asteroids_pos(obj_array_t *obj_array, int index)
{
    float len;
    sfVector2f new_pos = (sfVector2f){rand_nbr(0, 1), rand_nbr(0, 1)};
    sfVector2f earth = (sfVector2f){WID / 2 - 24, HEI / 2 - 24};
    sfIntRect rect = obj_array->asteroids[index].rect;

    new_pos.x *= WID;
    new_pos.y *= HEI;
    if (rand_nbr(0, 1) == 1)
        new_pos.x = rand_nbr(0, WID);
    else
        new_pos.y = rand_nbr(0, HEI);
    obj_array->asteroids[index].pos = new_pos;
    len = sqrt(pow(earth.x - new_pos.x, 2) + pow(earth.y - new_pos.y, 2));
    obj_array->asteroids[index].velocity.x = ((earth.x - new_pos.x) / len) * 3;
    obj_array->asteroids[index].velocity.y = ((earth.y - new_pos.y) / len) * 3;
    obj_array->asteroids[index].rect.left = 0;
    rect.left = 0;
    obj_array->asteroids[index].collided = sfFalse;
    sfSprite_setTextureRect(obj_array->asteroids[index].sprite, rect);
}