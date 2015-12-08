/*
** my_char_add.c for my_char_add in /home/alies_a
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Oct 27 15:58:35 2015 Arnaud Alies
** Last update Tue Oct 27 16:15:42 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char    *my_char_add(char **s, char c)
{
  char  *str;
  char  *result;
  int   x;

  str = *s;
  x = 0;
  result = malloc(sizeof(char) * (my_strlen(str) + 2));
  if (result == NULL)
    return (NULL);
  while (str[x] != '\0')
    {
      result[x] = str[x];
      x += 1;
    }
  result[x] = c;
  result[x + 1] = '\0';
  free(str);
  *s = result;
  return (result);
}
