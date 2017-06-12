/*
** my_itoa.c for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_2016_b2rush1/archive
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun  3 21:44:24 2017 benoit pingris
** Last update Sun Jun  4 13:28:26 2017 benoit pingris
*/

#include <stdlib.h>

char		*my_itoa(int nb)
{
  int		len;
  char		*str;
  int		tmp;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      ++len;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  str[len] = '\0';
  --len;
  while (len >= 0)
    {
      str[len] = nb % 10 + '0';
      nb /= 10;
      --len;
    }
  return (str);
}
