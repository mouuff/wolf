/*
** my_getptr.c for getptr in /home/alies/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Nov  5 16:11:33 2015 Arnaud Alies
** Last update Thu Nov  5 16:12:05 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char    *my_getptr(unsigned long nb, int base)
{
  char  *result;
  unsigned long   bin;

  if ((result = malloc(sizeof(char))) == NULL)
    return (NULL);
  result[0] = '\0';
  bin = 1;
  while (nb >= bin)
    {
      if (my_char_push(&result, BASE[nb / bin % base]) == NULL)
	return (NULL);
      bin *= base;
    }
  return (result);
}
