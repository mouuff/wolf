/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  8 11:49:36 2015 Arnaud Alies
** Last update Thu Oct 22 20:15:47 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

int     char_isalpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int     init_wordtab(char ***array, char **str, int size)
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

char    **my_str_to_wordtab(char *str)
{
  char  **result;
  char  *to_add;
  int   i;

  i = 0;
  if (init_wordtab(&result, &to_add, (my_strlen(str) + 1)))
    return (NULL);
  while (str[i] != '\0')
    {
      if (char_isalpha(str[i]))
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
