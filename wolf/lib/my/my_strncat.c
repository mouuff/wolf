/*
** my_strncat.c for my_strncat in /home/alies_a/rendu/Piscine_C_J07
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Oct  6 13:08:07 2015 Arnaud Alies
** Last update Wed Oct  7 21:47:56 2015 Arnaud Alies
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int   len;
  int   x;

  x = 0;
  len = my_strlen(dest);
  while (src[x] != '\0' && nb > x)
    {
      dest[x + len] = src[x];
      x += 1;
    }
  dest[x + len] = '\0';
  return (dest);
}
