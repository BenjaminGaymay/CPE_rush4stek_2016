/*
** main.c for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016/srcs
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Sat Jun  3 13:43:48 2017 benoit pingris
** Last update	Sun Jun 04 20:40:01 2017 Benjamin GAYMAY
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "basics.h"
#include "macro.h"
#include "get_next_line.h"

int		check_event(sfRenderWindow *window, t_info *car_info)
{
  if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
    sfRenderWindow_close(window);
  else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    car_info->speedf = car_info->speedf > 0 ? 0 : car_info->speedf - 0.10;
  else if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    car_info->speedf = car_info->speedf < 0 ? 0 : car_info->speedf + 0.10;
  else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    car_info->dir += 0.05;
  else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    car_info->dir -= 0.05;
  dprintf(1, "WHEELS_DIR:%f\n", car_info->dir);
  if (free_gnl(car_info) == ERROR)
    return (ERROR);
  if (car_info->speedf > 0)
    dprintf(1, "CAR_FORWARD:%f\n", car_info->speedf);
  else
    dprintf(1, "CAR_BACKWARDS:%f\n", car_info->speedf * -1);
  if (free_gnl(car_info) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int	start_simulation(sfRenderWindow *window, t_info *car_info)
{
  int		my_time;

  my_putstr("START_SIMULATION\n", 1);
  free_gnl(car_info);
  time(&car_info->time_1);
  while (sfRenderWindow_isOpen(window))
    {
      time(&car_info->time_2);
      my_time = car_info->time_2 - car_info->time_1;
      check_event(window, car_info);
      if (print_map(window, car_info, my_time) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int		set_info(t_info *car)
{
  sfUint8	*pixels;
  sfTexture	*texture;
  sfSprite	*sprite;
  int		i;

  car->speedf = 0;
  car->dir = 0;
  car->texture = sfTexture_create(WIDTH, HEIGHT);
  car->sprite = sfSprite_create();
  i = 0;
  if ((pixels = malloc(sizeof(*pixels) * WIDTH * HEIGHT * 4)) == NULL)
    return (ERROR);
  clear_pixel(pixels);
  car->pixel_buffer = pixels;
  car->nb_laps = 0;
  if ((car->laps = malloc(sizeof(char) * 10)) == NULL ||
      (car->timer = malloc(sizeof(char) * 5)) == NULL ||
      (car->angle = malloc(sizeof(char) * 5)) ==  NULL)
    return (ERROR);
  sfSprite_setTexture(car->sprite, car->texture, sfTrue);
  return (SUCCESS);
}

int			main(int ac, char **av)
{
  sfRenderWindow	*window;
  sfVideoMode		mode = {WIDTH, HEIGHT, 32};
  t_info		car_info;

  window = sfRenderWindow_create(mode, "*_*", sfClose, NULL);
  if (window == NULL)
    return (ERROR);
  if (set_info(&car_info) == ERROR)
    return (ERROR);
  sfRenderWindow_setFramerateLimit(window, 60);
  if (start_simulation(window, &car_info) == ERROR)
    return (ERROR);
  sfSprite_destroy(car_info.sprite);
  sfTexture_destroy(car_info.texture);
  sfRenderWindow_destroy(window);
  return (SUCCESS);
}
