/*
** my_str_islower.c for Day 6 Exercice 13 in /home/alies_a/rendu/Piscine_C_J06/ex_13
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 21:35:23 2015 Arnaud Alies
** Last update Mon Oct  5 21:37:52 2015 Arnaud Alies
*/

int     my_str_islower(char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if (!(str[x] >= 'a' && str[x] <= 'z'))
        {
          return (0);
        }
      x += 1;
    }
  return (1);
}
