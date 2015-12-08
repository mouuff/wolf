/*
** my_put_nbr.c for remake my_put_nbr in /home/alies_a/rendu/Tests
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 16:58:38 2015 Arnaud Alies
** Last update Mon Nov 16 13:21:50 2015 Arnaud Alies
*/

#include "my.h"

int		my_put_nbr(long long nb)
{
  long long	copy;
  long long	mul;
  int		count;

  count = 0;
  if (nb < 0)
    {
      nb = -nb;
      count += my_putchar('-');
    }
  mul = 1;
  copy = nb / 10;
  while (copy > 0)
    {
      mul *= 10;
      copy /= 10;
    }
  while (mul > 0)
    {
      count += my_putchar(nb / mul % 10 + '0');
      mul /= 10;
    }
  return (count);
}
