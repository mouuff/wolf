/*
** my_remove_dup.c for my_remove_dup in /home/alies/rendu/PSU_2015_my_ls/lib/my
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Nov 19 17:00:14 2015 Arnaud Alies
** Last update Thu Nov 19 17:01:35 2015 Arnaud Alies
*/

#include "my.h"

void    my_remove_dup(char *str, char c)
{
  char  cp;
  int   x;
  int   dup;

  x = 0;
  dup = 0;
  while (str[x] != '\0')
    {
      cp = str[x];
      if (str[x] == c && dup)
	{
	  my_char_remove(str, x);
	  x -= 1;
	}
      if (cp == c)
	dup = 1;
      else
	dup = 0;
      x += 1;
    }
}
