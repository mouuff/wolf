##
## Makefile for lib my in /home/alies/rendu/PSU_2015_my_ls_bootstrap/lib/my
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Mon Nov 16 11:50:08 2015 Arnaud Alies
## Last update Thu Nov 19 17:01:14 2015 Arnaud Alies
##

CC	=	gcc

NAME	=	libmy.a

INC	=	my.h

LPATH	=	../

IPATH	=	../../include/

CFLAGS	=	-Wall -Wextra

RM	=	rm -f

SRCS	=	my_array_append.c \
		my_array_len.c \
		my_char_add.c \
		my_char_append.c \
		my_char_count.c \
		my_char_push.c \
		my_char_remove.c \
		my_getbase.c \
		my_getptr.c \
		my_remove_dup.c \
		my_nbr_to_str.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_show_wordtab.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strfind.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_str_split.c \
		my_str_to_nbr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		p_is_printable.c \
		p_printf.c \
		p_show.c \
		p_show_hex.c \
		p_show_nb.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		cp $(NAME) $(LPATH)
		cp $(INC) $(IPATH)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(LPATH)$(NAME)

re:		fclean all
