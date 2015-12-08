/*
** p_show.c for p_show in /home/alies/rendu/PSU_2015_my_printf
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Nov  9 10:15:12 2015 Arnaud Alies
** Last update Mon Nov 16 11:36:10 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	show_printable(va_list *ap)
{
  char	*str;
  int	count;
  int	x;

  x = 0;
  count = 0;
  str = va_arg(*ap, char*);
  while (str[x] != '\0')
    {
      if (is_printable(str[x]))
	count += my_putchar(str[x]);
      else
	{
	  my_putchar('\\');
	  my_putstr(my_getbase_offset((int)str[x], 8, 3));
	  count += 4;
	}
      x += 1;
    }
  return (count);
}

int     show_str(va_list *ap)
{
  char	*buffer;

  buffer = va_arg(*ap, char*);
  if (buffer == NULL)
    return (0);
  my_putstr(buffer);
  return (my_strlen(buffer));
}

int	show_char(va_list *ap)
{
  my_putchar((char)va_arg(*ap, int));
  return (1);
}
