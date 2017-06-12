/*
** text.c for rush in /home/benjamin.g/delivery/CPE_rush4stek_2016
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sun Jun  4 19:05:51 2017 Benjamin GAYMAY
** Last update	Sun Jun 04 20:44:19 2017 Benjamin GAYMAY
*/

#include <SFML/Graphics.h>
#include "basics.h"

void	display(char *str, sfRenderWindow *window, t_opt *opt, int origin)
{
  sfText	*text;
  sfFont	*font;
  sfVector2f	pos;

  pos.x = 90;
  pos.y = 50;
  text = sfText_create();
  font = sfFont_createFromFile("open.ttf");
  sfText_setString(text, str);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, opt->size);
  sfText_setColor(text, sfWhite);
  sfText_rotate(text, opt->angle);
  sfText_setPosition(text, opt->pos);
  if (origin)
    sfText_setOrigin(text, pos);
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  sfFont_destroy(font);
}
