/*
** lidar.c for CPE_rush4stek_2016
**
** Made by	Benjamin GAYMAY
** Login	benjamin.gaymay@epitech.eu
**
** Started on	Sun Jun 04 10:59:10 2017 Benjamin GAYMAY
** Last update	Sun Jun 04 13:02:39 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "macro.h"
#include "basics.h"
#include "get_next_line.h"

char	**str_tab(char *s)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (s[i])
    {
      if ((tab[j] = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
	return (NULL);
      k = 0;
      while (s[i] == ':')
	++i;
      while (s[i] && s[i] != ':')
	tab[j][k++] = s[i++];
      tab[j++][k] = '\0';
    }
  tab[j] = NULL;
  return (tab);
}

void	free_tab(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      free(array[i]);
      ++i;
    }
  free(array);
}

int	get_lidar(int *lidar, t_info *car)
{
  char	*s;
  char	**tab;
  int	i;

  i = 0;
  dprintf(1, "GET_INFO_LIDAR\n");
  if ((s = get_next_line(0)) == NULL)
    return (ERROR);
  check_exit(s, car);
  if ((tab = str_tab(s)) == NULL)
    return (ERROR);
  while (i < LIDAR_MAX)
    {
      lidar[i] = atoi(tab[i + 3]);
      ++i;
    }
  free(s);
  free_tab(tab);
  return (SUCCESS);
}

void	print_wall(int *lidar, sfUint8 *pixel_buffer, int y, int x)
{
  int	i;
  int	j;

  i = LIDAR_X;
  while (i != LIDAR_X + 5)
    {
      j = 0;
      while (j != 5)
	{
	  color_pixel(pixel_buffer, y + j, x * 2 + i, sfRed);
	  ++j;
	}
      ++i;
    }
}

int		print_lidar(t_info *car)
{
  int		lidar[LIDAR_MAX];
  int		x;
  int		y;

  x = 0;
  if (get_lidar(lidar, car) == ERROR)
    return (ERROR);
  clear_pixel(car->pixel_buffer);
  while (x < LIDAR_MAX)
    {
      y = CAR_Y - lidar[x] * 3 / 100;
      if (lidar[x] >= 0 && lidar[x] <= 2000)
	print_wall(lidar, car->pixel_buffer, y, x);
      ++x;
    }
  print_square(car->pixel_buffer, CAR_Y + 3, CAR_X, sfGreen);
  print_empty_square(car->pixel_buffer, RADAR_Y, RADAR_X, sfBlue);
  sfTexture_updateFromPixels(car->texture, car->pixel_buffer,
			       WIDTH, HEIGHT, 0, 0);
  return (SUCCESS);
}
