##
## Makefile for wolf in /home/alies/rendu/gfx_wolf3d
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Wed Dec  2 20:32:05 2015 Arnaud Alies
## Last update Wed Dec  9 21:44:47 2015 Arnaud Alies
##

NAME    =       wolf3d

CC	=	gcc

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-L$(LIB) -I$(INC) -lmy \
		-Wall -Wextra -g

SRC	=	./src/

TCORE	=	./tcore/

ENGINE	=	./src/engine/

MAP	=	./src/map/

SRCS	=	$(SRC)main.c \
		$(TCORE)tekpixel.c \
		$(TCORE)vecnorm.c \
		$(TCORE)go.c \
		$(MAP)load_map.c \
		$(MAP)show_map.c \
		$(ENGINE)pixfill.c \
		$(ENGINE)ray.c \
		$(ENGINE)find_hit.c \
		$(ENGINE)disp.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		makelib $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:		cleanlib
		$(RM) $(OBJS)

fclean:		fcleanlib clean
		$(RM) $(NAME)

re:		fclean all

makelib:
		(cd lib/my ; make)

cleanlib:
		(cd lib/my ; make clean)

fcleanlib:
		(cd lib/my ; make fclean)

.PHONY: all clean fclean re makelib cleanlib fcleanlib
