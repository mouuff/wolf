/*
** my_putstr.c for Day 4 Exercice 3 in /home/alies_a/rendu/Piscine_C_J04
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  1 11:53:30 2015 Arnaud Alies
** Last update Thu Nov 19 15:58:24 2015 Arnaud Alies
*/

#include "my.h"

int	my_putstr(const char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      my_putchar(str[x]);
      x += 1;
    }
  return (0);
}
