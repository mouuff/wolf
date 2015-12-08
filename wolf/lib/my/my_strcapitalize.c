/*
** my_strcapitalize.c for Day 6 Exercice 10 in /home/alies_a/rendu/Piscine_C_J06/ex_10
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 19:03:39 2015 Arnaud Alies
** Last update Wed Oct  7 21:15:57 2015 Arnaud Alies
*/

void	capitalize(char *str, int x)
{
  if (str[x] >= 'a' && str[x] <= 'z')
    {
      str[x] -= 'a' - 'A';
    }
}

char	*my_strcapitalize(char *str)
{
  int cap_next;
  int x;

  x = 0;
  cap_next = 0;
  capitalize(str, x);
  while (str[x] != '\0')
    {
      if (cap_next)
	{
	  cap_next = 0;
	  capitalize(str, x);
	}
      if (str[x] == ' ' || str[x] == '-' || str[x] == '+')
	{
	  cap_next = 1;
	}
      x += 1;
    }
  return (str);
}
