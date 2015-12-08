/*
** my_strcmp.c for Day 6 Exercice 6 in /home/alies_a/rendu/Piscine_C_J06/ex_06
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 16:58:16 2015 Arnaud Alies
** Last update Mon Oct  5 17:57:44 2015 Arnaud Alies
*/

int	my_strcmp(char *s1, char *s2)
{
  char	diff;
  int	x;

  diff = 0;
  x = 0;
  while (s1[x] != '\0' && s2[x] != '\0')
    {
      diff = s1[x] - s2[x];
      if (diff != 0)
	return (diff);
      x += 1;
    }
  return (0);
}
