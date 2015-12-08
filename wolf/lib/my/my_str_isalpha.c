/*
** my_str_isalpha.c for Day 6 Exercice 11 in /home/alies_a/rendu/Piscine_C_J06/ex_11
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 20:35:25 2015 Arnaud Alies
** Last update Mon Oct  5 21:02:32 2015 Arnaud Alies
*/

int	my_str_isalpha(char *str)
{
  int	x;

  x = 0;
  while (str[x] != '\0')
    {
      if ((str[x] >= 'A' && str[x] <= 'Z') || (str[x] >= 'a' && str[x] <= 'z'))
	{
	  x += 1;
	}
      else
	{
	  return (0);
	}
    }
  return (1);
}
