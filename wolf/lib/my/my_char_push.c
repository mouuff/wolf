/*
** my_char_push.c for char push in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct 21 22:34:02 2015 Arnaud Alies
** Last update Thu Oct 22 09:18:32 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char    *my_char_push(char **s, char c)
{
  char	*str;
  char  *result;
  int   x;

  str = *s;
  x = 0;
  result = malloc(sizeof(char) * (my_strlen(str) + 2));
  if (result == NULL)
    return (NULL);
  result[0] = c;
  result[1] = '\0';
  while (str[x] != '\0')
    {
      my_char_append(result, str[x]);
      x += 1;
    }
  free(str);
  *s = result;
  return (result);
}
