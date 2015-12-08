/*
** my_str_split.c for my_str_split in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  8 20:57:10 2015 Arnaud Alies
** Last update Thu Oct 22 14:23:43 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

int     init_str_split(char ***array, char **str, int size)
{
  *array = malloc(sizeof(char*) * size);
  if (*array == NULL)
    return (1);
  *str = malloc(sizeof(char) * size);
  if (*str == NULL)
    return (1);
  *str[0] = '\0';
  *array[0] = NULL;
  return (0);
}

char    **my_str_split(char *str, char d)
{
  char  **result;
  char  *to_add;
  int   i;

  i = 0;
  if (init_str_split(&result, &to_add, (my_strlen(str) + 1)))
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] != d)
        {
          my_char_append(to_add, str[i]);
        }
      else if (my_strlen(to_add) > 0)
        {
          my_array_append(result, to_add);
          to_add[0] = '\0';
        }
      i += 1;
    }
  my_array_append(result, to_add);
  free(to_add);
  return (result);
}
