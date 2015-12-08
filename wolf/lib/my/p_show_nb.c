/*
** p_show_nb.c for shownb in /home/alies/rendu/PSU_2015_my_printf/my
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Nov  9 10:13:42 2015 Arnaud Alies
** Last update Mon Nov 16 13:17:32 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int     show_oct(va_list *ap)
{
  char	*buffer;
  int	x;

  buffer = my_getunsigned((unsigned int)va_arg(*ap, unsigned int), 8, 0);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x);
}

int     show_bin(va_list *ap)
{
  char  *buffer;
  int	x;

  buffer = my_getunsigned((unsigned int)va_arg(*ap, unsigned int), 2, 0);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x);
}

int     show_unsigned(va_list *ap)
{
  char  *buffer;
  int	x;

  buffer = my_getunsigned((unsigned int)va_arg(*ap, unsigned int), 10, 0);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x);
}

int     show_int(va_list *ap)
{
  int	x;

  x = my_put_nbr((long long)va_arg(*ap, long long));
  return (x);
}
