/*
** my_strupcase.c for Day 6 Exercice 8 in /home/alies_a/rendu/Piscine_C_J06/ex_08
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 18:31:34 2015 Arnaud Alies
** Last update Mon Oct  5 18:39:36 2015 Arnaud Alies
*/

char	*my_strupcase(char *str)
{
  int	x;

  x = 0;
  while (str[x] != '\0')
    {
      if (str[x] >= 'a' && str[x] <= 'z')
	{
	  str[x] -= 'a' - 'A';
	}
      x += 1;
    }
  return (str);
}
