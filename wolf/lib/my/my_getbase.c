/*
** my_getbase.c for get base in /home/alies/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Nov  5 15:36:24 2015 Arnaud Alies
** Last update Mon Nov 16 11:17:22 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char    *my_getbase(int nb, int base)
{
  char  *result;
  int   bin;
  int   neg;

  neg = (nb < 0 ? 1 : 0);
  nb = (nb < 0 ? -nb : nb);
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
  if (neg)
    if (my_char_push(&result, '-') == NULL)
      return (NULL);
  return (result);
}

char		*my_getbase_offset(int nb, int base, int offset)
{
  char		*result;
  int		bin;
  int		neg;
  int		x;

  x = 0;
  neg = (nb < 0 ? 1 : 0);
  nb = (nb < 0 ? -nb : nb);
  if ((result = malloc(sizeof(char))) == NULL)
    return (NULL);
  result[0] = '\0';
  bin = 1;
  while (x < offset)
    {
      if (my_char_push(&result, BASE[nb / bin % base]) == NULL)
	return (NULL);
      bin *= base;
      x += 1;
    }
  if (neg)
    if (my_char_push(&result, '-') == NULL)
      return (NULL);
  return (result);
}

char            *my_getunsigned(unsigned long nb, int base, int upper)
{
  unsigned long bin;
  char          *result;
  char          *basestr;

  basestr = (upper ? BASE_U : BASE);
  if ((result = malloc(sizeof(char))) == NULL)
    return (NULL);
  result[0] = '\0';
  bin = 1;
  while (nb >= bin)
    {
      if (my_char_push(&result, basestr[nb / bin % base]) == NULL)
	return (NULL);
      bin *= base;
    }
  return (result);
}
