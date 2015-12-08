/*
** my_revstr.c for my_revstr in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct 19 11:04:50 2015 Arnaud Alies
** Last update Mon Oct 19 11:05:25 2015 Arnaud Alies
*/

#include "my.h"

char    *my_revstr(char *str)
{
  char  buffer;
  int   x;
  int   len;

  x = 0;
  len = my_strlen(str);
  while (x < len / 2)
    {
      buffer = str[x];
      str[x] = str[len - x - 1];
      str[len - x - 1] = buffer;
      x += 1;
    }
  return (str);
}
