/*
** my_char_append.c for my_char_append in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 21:38:01 2015 Arnaud Alies
** Last update Wed Oct  7 21:50:12 2015 Arnaud Alies
*/

#include "my.h"

int     my_char_append(char *str, char c)
{
  int   len;

  len = my_strlen(str);
  str[len] = c;
  str[len + 1] = '\0';
  return (0);
}
