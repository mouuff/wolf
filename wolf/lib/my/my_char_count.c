/*
** my_count_char.c for my_count_char in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 21:34:32 2015 Arnaud Alies
** Last update Wed Oct  7 21:35:36 2015 Arnaud Alies
*/

int     my_char_count(char *str, char c)
{
  int   x;
  int   count;

  x = 0;
  count = 0;
  while (str[x] != '\0')
    {
      if (str[x] == c)
        count += 1;
      x += 1;
    }
  return (count);
}
