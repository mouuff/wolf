/*
** my_strlowcase.c for Day 6 Exercice 9 in /home/alies_a/rendu/Piscine_C_J06/ex_09
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 18:55:05 2015 Arnaud Alies
** Last update Mon Oct  5 18:56:22 2015 Arnaud Alies
*/

char    *my_strlowcase(char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if (str[x] >= 'A' && str[x] <= 'Z')
        {
          str[x] += 'a' - 'A';
        }
      x += 1;
    }
  return (str);
}
