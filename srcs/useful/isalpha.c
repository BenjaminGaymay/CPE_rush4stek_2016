/*
** isalpha.c for rush in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun  3 19:33:53 2017 benoit pingris
** Last update Sat Jun  3 19:39:21 2017 benoit pingris
*/

#include "macro.h"

int	is_alpha(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (!(s[i] >= '0' && s[i] <= '9' || s[i] == '.' || s[i] == '-'))
	return (ERROR);
      ++i;
    }
  return (SUCCESS);
}
