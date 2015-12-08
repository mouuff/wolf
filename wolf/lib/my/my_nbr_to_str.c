/*
** my_nbr_to_str.c for number to str in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct 21 15:08:34 2015 Arnaud Alies
** Last update Thu Oct 22 09:33:00 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

void	init_loop(int nb, int *mul, int *copy, int *x)
{
  *mul = 1;
  *copy = nb / 10;
  while (*copy > 0)
    {
      *mul *= 10;
      *copy /= 10;
      *x += 1;
    }
}

char    *my_nbr_to_str(int nb)
{
  char  *result;
  int   copy;
  int   mul;
  int   x;
  int	minus;

  x = 1;
  minus = 0;
  if (nb < 0)
    {
      minus = 1;
      nb = -nb;
    }
  init_loop(nb, &mul, &copy, &x);
  result = malloc(sizeof(char) * (x + 2));
  result[0] = '\0';
  if (minus)
    my_char_append(result, '-');
  while (mul > 0)
    {
      my_char_append(result, nb / mul % 10 + '0');
      mul /= 10;
    }
  return (result);
}
