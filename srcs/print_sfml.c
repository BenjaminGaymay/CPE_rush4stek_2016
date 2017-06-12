/*
** print_sfml.c for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Sat Jun  3 22:00:57 2017 benoit pingris
** Last update	Sun Jun 04 21:15:42 2017 Benjamin GAYMAY
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Texture.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "basics.h"
#include "macro.h"
#include "get_next_line.h"

char		*get_speed(char *s)
{
  int		i;
  int		j;
  char		*speed;

  if ((speed = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return (NULL);
  i = 22;
  j = 0;
  if (s[i] == '-')
    ++i;
  while (s[i] && s[i] != ':')
    speed[j++] = s[i++];
  speed[j] = '\0';
  free(s);
  return (speed);
}

int	speed_car(t_info *car, char *info)
{
  if ((info = get_speed(info)) == NULL)
    return (ERROR);
  if (is_alpha(info) == SUCCESS)
    {
      car->speed = info;
      if ((car->speed = mallocat(car->speed, " km/h")) == NULL)
	return (ERROR);
    }
  return (SUCCESS);
}

int	get_info(t_info *car, char *info, int timer)
{
  if (speed_car(car, info) == ERROR)
    return (ERROR);
  if (timer % 60 > 9)
    sprintf(car->timer, "0%d : %d", timer / 60, timer % 60);
  else
    sprintf(car->timer, "0%d : 0%d", timer / 60, timer % 60);
  return (SUCCESS);
}

t_opt	setup_opt(int x, int y, int size, int angle)
{
  t_opt	opt;

  opt.pos.x = x;
  opt.pos.y = y;
  opt.size = size;
  opt.angle = angle;
  return (opt);
}

void	print_info(t_info *car, sfRenderWindow *window)
{
  t_opt	opt;

  opt = setup_opt(WIDTH - 200, HEIGHT - 100, 30, 0);
  display(car->speed, window, &opt, 0);
  free(car->speed);
  opt = setup_opt(25, 40, 30, 0);
  display(car->timer, window, &opt, 0);
  opt = setup_opt(25, 100, 30, 0);
  sprintf(car->laps, "Lap(s) : %d", car->nb_laps);
  display(car->laps, window, &opt, 0);
  opt = setup_opt(WIDTH - 200, 10, 20, 0);
  display("Press \"Q\" key to Quit", window, &opt, 0);
  opt = setup_opt(360, 325, 30, car->dir * -90);
  sprintf(car->angle, "(---------O---------)", car->dir);
  display(car->angle, window, &opt, 1);
}
/* void		dashboard(sfRenderWindow *window) */
/* { */
/*   sfTexture	*texture; */
/*   sfSprite	*sprite; */

/*   texture = sfTexture_createFromFile("dashboard.png", NULL); */
/*   sprite = sfSprite_create(); */
/*   sfSprite_setTexture(sprite, texture, sfTrue); */
/*   sfRenderWindow_drawSprite(window, sprite, NULL); */
/* } */
int	print_map(sfRenderWindow *window, t_info *car, int timer)
{
  char	*info;

  my_putstr("GET_CURRENT_SPEED\n", 1);
  if ((info = get_next_line(0)) == NULL)
    return (ERROR);
  check_exit(info, car);
  if (print_lidar(car) == ERROR)
    return (ERROR);
  if (get_info(car, info, timer) == ERROR)
    return (ERROR);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, car->sprite, NULL);
  print_info(car, window);
  sfRenderWindow_display(window);
  return (SUCCESS);
}
