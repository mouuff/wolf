/*
** my_printf.c for my_printf in /home/alies/rendu/PSU_2015_my_printf
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Nov  6 15:31:23 2015 Arnaud Alies
** Last update Thu Nov 19 15:59:48 2015 Arnaud Alies
*/

#include <stdarg.h>
#include "my.h"

int	find_func(char c)
{
  char	*list;
  int	x;

  x = 0;
  list = "pxobSdsXiuc";
  while (list[x] != '\0')
    {
      if (c == list[x])
	return (x);
      x += 1;
    }
  return (-1);
}

int	check(va_list *ap, const char *str)
{
  int	x;
  disp	func[11];

  func[0] = &show_pointer;
  func[1] = &show_hex;
  func[2] = &show_oct;
  func[3] = &show_bin;
  func[4] = &show_printable;
  func[5] = &show_int;
  func[6] = &show_str;
  func[7] = &show_hex_up;
  func[8] = &show_int;
  func[9] = &show_unsigned;
  func[10] = &show_char;
  x = find_func(str[0]);
  if (x != -1)
    return (func[x](ap));
  my_putchar('%');
  my_putchar(str[0]);
  return (2);
}

int            my_printf(const char *str, ...)
{
  va_list       ap;
  int           len;
  int           x;
  int		count;

  len = my_strlen(str);
  count = 0;
  x = 0;
  va_start(ap, str);
  while (str[x] != '\0')
    {
      if (len > x + 1 && str[x] == '%')
	{
	  x += 1;
	  if (str[x] == '%')
	    count += my_putchar('%');
	  else
	    count += check(&ap, str + x);
	}
      else
	count += my_putchar(str[x]);
      x += 1;
    }
  va_end(ap);
  return (count);
}
