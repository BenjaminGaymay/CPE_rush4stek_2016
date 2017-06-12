/*
** pixel.c for rush in /home/benjamin.g/delivery/CPE_rush4stek_2016
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sun Jun  4 18:18:10 2017 Benjamin GAYMAY
** Last update Sun Jun  4 19:03:37 2017 Benjamin GAYMAY
*/

#include <SFML/Graphics.h>
#include "basics.h"
#include "macro.h"

void	color_pixel(sfUint8 *pixel_buffer, int y, int x, sfColor color)
{
  pixel_buffer[(WIDTH * y + x) * 4] = color.r;
  pixel_buffer[(WIDTH * y + x) * 4 + 1] = color.g;
  pixel_buffer[(WIDTH * y + x) * 4 + 2] = color.b;
  pixel_buffer[(WIDTH * y + x) * 4 + 3] = color.a;
}

void	print_empty_square(sfUint8 *pixel_buffer, int y, int x, sfColor color)
{
  int	i;
  int	j;

  j = 0;
  while (j != RADAR_SIZE + 1)
    {
      i = 0;
      if (j <= 1 || j >= RADAR_SIZE - 1)
	{
	  while (i != RADAR_SIZE + 1)
	    {
	      color_pixel(pixel_buffer, y + j, x + i, color);
	      ++i;
	    }
	}
      color_pixel(pixel_buffer, y + j, x, color);
      color_pixel(pixel_buffer, y + j, x + 1, color);
      color_pixel(pixel_buffer, y + j, x + RADAR_SIZE, color);
      color_pixel(pixel_buffer, y + j, x + RADAR_SIZE - 1, color);
      ++j;
    }
}

void	print_square(sfUint8 *pixel_buffer, int y, int x, sfColor color)
{
  int	i;
  int	j;

  j = 0;
  while (j != CAR_HEIGHT)
    {
      i = 0;
      while (i != CAR_WIDTH)
	{
	  color_pixel(pixel_buffer, y + j, x - CAR_WIDTH / 2 + i, color);
	  ++i;
	}
      ++j;
    }
}

void	clear_pixel(sfUint8 *pixel_buffer)
{
  int	i;

  i = 0;
  while (i < WIDTH * HEIGHT * 4)
    {
      pixel_buffer[i] = 0;
      ++i;
    }
}
