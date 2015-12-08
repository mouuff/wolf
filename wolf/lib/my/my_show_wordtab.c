/*
** my_array_show.c for my_array_show in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 22:09:42 2015 Arnaud Alies
** Last update Thu Oct  8 11:30:12 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

int    my_show_wordtab(char **tab)
{
  int   x;

  x = 0;
  while (tab[x] != 0)
    {
      my_putstr(tab[x]);
      my_putchar('\n');
      x += 1;
    }
  return (0);
}
