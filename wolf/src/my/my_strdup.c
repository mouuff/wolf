/*
** my_strdup.c for strdup in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 20:58:21 2015 Arnaud Alies
** Last update Thu Nov 19 15:57:57 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char    *my_strdup(const char *src)
{
  char	*dest;

  dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
