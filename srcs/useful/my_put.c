/*
** my_put.c for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016/srcs/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun  3 14:07:24 2017 benoit pingris
** Last update Sat Jun  3 14:13:51 2017 benoit pingris
*/

#include <unistd.h>
#include <string.h>

void	my_putchar(char a, int stream)
{
  write(stream, &a, 1);
}

void	my_putstr(char *s, int stream)
{
  write(stream, s, strlen(s));
}

void	my_putnbr(int nb, int stream)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-', stream);
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + '0', stream);
  if (nb > 9)
    {
      my_putnbr(nb / 10, stream);
      my_putnbr(nb % 10, stream);
    }
}
