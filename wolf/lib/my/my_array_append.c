/*
** my_array_append.c for array_append in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 21:27:49 2015 Arnaud Alies
** Last update Tue Oct 20 13:00:50 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

int     my_array_append(char **array, char *str)
{
  int   len;
  char  *s;

  s = my_strdup(str);
  if (s == NULL)
    return (1);
  len = my_array_len(array);
  array[len] = s;
  array[len + 1] = NULL;
  return (0);
}
