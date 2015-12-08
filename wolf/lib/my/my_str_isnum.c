/*
** my_str_isnum.c for Day 6 Exercice 12 in /home/alies_a/rendu/Piscine_C_J06/ex_12
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 21:11:59 2015 Arnaud Alies
** Last update Mon Oct  5 21:24:30 2015 Arnaud Alies
*/

int     my_str_isnum(char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if (!(str[x] >= '0' && str[x] <= '9'))
	{
	  return (0);
	}
      x += 1;
    }
  return (1);
}
