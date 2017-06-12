##
## Makefile for rush4stek in /home/benoit.pingris/delivery/CPE/CPE_rush4stek_2016
##
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
##
## Started on  Sat Jun  3 13:43:32 2017 benoit pingris
## Last update Sun Jun  4 19:34:40 2017 benoit pingris
### Last update Sun Jun  4 19:06:38 2017 Benjamin GAYMAY
##

CC	=	gcc

NAME	=	rush4stek

SRC	=	srcs/main.c			\
		srcs/print_sfml.c		\
		srcs/useful/my_itoa.c		\
		srcs/useful/mallocat.c		\
		srcs/useful/isalpha.c		\
		srcs/gnl/get_next_line.c	\
		srcs/useful/free_gnl.c		\
		srcs/pixel.c			\
		srcs/lidar.c			\
		srcs/text.c			\
		srcs/useful/my_put.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lc_graph_prog

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
