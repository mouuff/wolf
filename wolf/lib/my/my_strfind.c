/*
** my_strfind.c for my_strfind.c in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  8 21:15:32 2015 Arnaud Alies
** Last update Thu Oct  8 21:16:41 2015 Arnaud Alies
*/

#include "my.h"

int     my_strfind(char *str, char *to_find)
{
  int   lock;
  int   found;
  int   x;

  found = 0;
  x = 0;
  lock = 0;
  while (str[x] != '\0' && to_find[found] != '\0')
    {
      if (str[x] == to_find[found])
        found += 1;
      else
        found = 0;
      if (found == 1)
        lock = x;
      if (found == my_strlen(to_find))
        return (lock);
      x += 1;
    }
  return (-1);
}
