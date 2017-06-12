/*
** mallocat.c for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Sun Jun  4 12:24:03 2017 benoit pingris
** Last update	Sun Jun 04 14:53:14 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <string.h>

char	*mallocat(char *s1, const char *s2)
{
  int	i;
  int	f;
  char	*new;

  i = strlen(s1) + strlen(s2);
  if ((new = calloc(i + 1, sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
    {
      new[i] = s1[i];
      ++i;
    }
  f = 0;
  while (s2[f])
    {
      new[i] = s2[f];
      ++i;
      ++f;
    }
  free(s1);
  return (new);
}
