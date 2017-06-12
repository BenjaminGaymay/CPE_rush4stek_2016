/*
** macro.h for rush4sek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016/include
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Sat Jun  3 13:47:47 2017 benoit pingris
** Last update Sun Jun  4 19:25:49 2017 Benjamin GAYMAY
*/

#ifndef MACRO_H_
# define MACRO_H_

# define SUCCESS 0
# define FAILURE 1
# define ERROR 84

# define WIDTH 800
# define HEIGHT 600

# define CAR_Y 520
# define CAR_X 100
# define RADAR_Y CAR_Y - 70
# define RADAR_X CAR_X - RADAR_SIZE / 2
# define LIDAR_X RADAR_X + LIDAR_MAX / 2

# define RADAR_SIZE 100
# define CAR_HEIGHT 16
# define CAR_WIDTH 8

# define LIDAR_MAX 32

#endif /* !MACRO_H_ */
