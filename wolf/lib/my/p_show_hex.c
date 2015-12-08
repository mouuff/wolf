/*
** p_show_hex.c for p_show_hex in /home/alies/rendu/PSU_2015_my_printf/my
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Nov 10 16:03:18 2015 Arnaud Alies
** Last update Mon Nov 16 11:36:43 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int     	show_pointer(va_list *ap)
{
  char		*buffer;
  unsigned long	value;
  int		x;

  value = (unsigned long)va_arg(*ap, unsigned long);
  if (value == 0)
    {
      my_putstr("(nil)");
      return (3);
    }
  buffer = my_getunsigned(value, 16, 0);
  if (buffer == NULL)
    return (0);
  my_putstr("0x");
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x + 2);
}

int     show_hex(va_list *ap)
{
  char  *buffer;
  int	x;

  buffer = my_getunsigned((unsigned int)va_arg(*ap, unsigned int), 16, 0);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x);
}

int     show_hex_up(va_list *ap)
{
  char  *buffer;
  int	x;

  buffer = my_getunsigned((unsigned int)va_arg(*ap, unsigned int), 16, 1);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  x = my_strlen(buffer);
  free(buffer);
  return (x);
}
