##
## Makefile for fire in /home/alies/rendu/gfx_incendie
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Dec  4 21:57:46 2015 Arnaud Alies
## Last update Tue Dec  8 18:46:24 2015 Arnaud Alies
##

NAME    =       a.out

CC	=	gcc

INC	=	./include/

CFLAGS	=	-Wall -Wextra -g \
		-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC)

SRC	=	./src/

CORE	=	./src/core/

SRCS	=	$(SRC)main.c \
		$(CORE)tekpixel.c \
		$(CORE)pixfill.c \
		load_bitmap.c \
		all_grey.c \
		binarize.c

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
