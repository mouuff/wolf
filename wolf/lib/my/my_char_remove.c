/*
** my_char_remove.c for my_char_remove in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct 22 13:10:51 2015 Arnaud Alies
** Last update Thu Oct 22 13:11:27 2015 Arnaud Alies
*/

void    my_char_remove(char *str, int pos)
{
  int   x;
  int   offset;

  offset = 0;
  x = 0;
  while (str[x] != '\0')
    {
      if (x == pos)
        offset = 1;
      str[x] = str[x + offset];
      x += 1;
    }
}
