/*
** free_gnl.c for CPE_rush4stek_2016
**
** Made by	Benjamin GAYMAY
** Login	benjamin.gaymay@epitech.eu
**
** Started on	Sat Jun 03 21:59:00 2017 Benjamin GAYMAY
** Last update	Sun Jun 04 15:01:20 2017 Benjamin GAYMAY
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include "macro.h"
#include "get_next_line.h"

void	check_exit(char *s, t_info *car)
{
  if (strstr(s, "Track Cleared") != NULL)
    dprintf(1, "STOP_SIMULATION\n");
  if (strstr(s, "Lap Cleared") != NULL)
    ++car->nb_laps;
}

int	free_gnl(t_info *car)
{
  char	*s;

  if ((s = get_next_line(0)) == NULL)
    return (ERROR);
  check_exit(s, car);
  free(s);
  return (SUCCESS);
}
