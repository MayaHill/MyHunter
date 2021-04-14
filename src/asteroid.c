/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** asteroid.c
*/

#include <my_hunter.h>
#include <math.h>

obj_array_t create_asteroids_array(void)
{
    obj_array_t obj_array;

    obj_array.size = 0;
    return (obj_array);
}

obj_array_t add_asteroid(sfRenderWindow *win, obj_array_t objs, char *path)
{
    asteroid_t asteroid;
    int size = objs.size;

    if (size >= 99)
        sfRenderWindow_close(win);
    asteroid.pos = (sfVector2f){-50, -50};
    asteroid.texture = sfTexture_createFromFile(path, NULL);
    asteroid.sprite = sfSprite_create();
    asteroid.clock = sfClock_create();
    asteroid.rect = (sfIntRect){0, 0, 64, 64};
    asteroid.collided = sfFalse;
    sfSprite_setTexture(asteroid.sprite, asteroid.texture, sfTrue);
    sfSprite_setTextureRect(asteroid.sprite, asteroid.rect);
    sfSprite_setPosition(asteroid.sprite, asteroid.pos);
    objs.asteroids[size] = asteroid;
    objs.size += 1;
    return (objs);
}

void display_asteroids(sfRenderWindow *window, obj_array_t *obj_array)
{
    for (int i = 0; i < obj_array->size; i++)
        sfRenderWindow_drawSprite(window, obj_array->asteroids[i].sprite, NULL);
}

void destroy_asteroids(obj_array_t obj_array)
{
    for (int i = 0; i < obj_array.size; i++) {
        sfTexture_destroy(obj_array.asteroids[i].texture);
        sfSprite_destroy(obj_array.asteroids[i].sprite);
        sfClock_destroy(obj_array.asteroids[i].clock);
    }
}