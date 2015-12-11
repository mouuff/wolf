##
## Makefile for wolf in /home/alies/rendu/gfx_wolf3d
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Wed Dec  2 20:32:05 2015 Arnaud Alies
## Last update Fri Dec 11 21:18:56 2015 Arnaud Alies
##

NAME    =       wolf3d

CC	=	gcc

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC) \
		-Wall -Wextra -g

SRC	=	./src/

TCORE	=	./tcore/

ENGINE	=	./src/engine/

MAP	=	./src/map/

MY	=	./src/my/

SRCS	=	$(SRC)main.c \
		$(SRC)load_bmp.c \
		$(TCORE)tekpixel.c \
		$(TCORE)vecnorm.c \
		$(TCORE)go.c \
		$(MAP)load_map.c \
		$(ENGINE)pixfill.c \
		$(ENGINE)ray.c \
		$(ENGINE)find_hit.c \
		$(ENGINE)disp.c \
		$(ENGINE)get_pixel.c \
		$(MY)my_putchar.c \
		$(MY)my_putstr.c \
		$(MY)my_strcat.c \
		$(MY)my_strcpy.c \
		$(MY)my_strdup.c \
		$(MY)my_strlen.c \
		$(MY)my_str_to_nbr.c \

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re makelib cleanlib fcleanlib
