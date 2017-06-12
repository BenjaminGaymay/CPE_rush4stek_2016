/*
** basics.h for CPE_rush4stek_2016
**
** Made by	Benjamin GAYMAY
** Login	benjamin.gaymay@epitech.eu
**
** Started on	Sat Jun 03 15:28:36 2017 Benjamin GAYMAY
** Last update	Sun Jun 04 13:06:38 2017 Benjamin GAYMAY
*/

#ifndef BASICS_H_
# define BASICS_H_

#include <SFML/Graphics.h>
#include <time.h>

typedef struct	s_opt
{
  sfVector2f	pos;
  sfColor	color;
  int		size;
  int		angle;
}		t_opt;

typedef struct	s_info
{

  sfUint8	*pixel_buffer;
  sfTexture	*texture;
  sfSprite	*sprite;
  time_t	time_1;
  time_t	time_2;
  float		speedf;
  float		dir;
  char		*angle;
  char	       	*speed;
  char 		*timer;
  char		*laps;
  int		nb_laps;
}		t_info;

char	*mallocat(const char *, const char *);
char	*my_itoa(int);

int	is_alpha(char *);
int	free_gnl(t_info *);

int	get_lidar();

int	print_map(sfRenderWindow *, t_info *, int);
int	print_lidar(t_info *);

void	check_exit(char *, t_info *);
void	clear_pixel(sfUint8 *);
void	color_pixel(sfUint8 *, int, int, sfColor);
void	print_square(sfUint8 *, int, int, sfColor);
void	print_empty_square(sfUint8 *, int, int, sfColor);

void	my_putstr(char *, int);
void	display(char *, sfRenderWindow *, t_opt *, int);

#endif /* !BASICS_H_ */
