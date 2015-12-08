/*
** my_str_isupper.c for Day 6 Exercice 14 in /home/alies_a/rendu/Piscine_C_J06/ex_14
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 21:40:50 2015 Arnaud Alies
** Last update Mon Oct  5 21:41:18 2015 Arnaud Alies
*/

int     my_str_isupper(char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if (!(str[x] >= 'A' && str[x] <= 'Z'))
        {
          return (0);
        }
      x += 1;
    }
  return (1);
}
