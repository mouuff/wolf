/*
** is_printable.c for is printable? in /home/alies/rendu/PSU_2015_my_printf/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Nov  5 20:14:53 2015 Arnaud Alies
** Last update Fri Nov  6 14:36:18 2015 Arnaud Alies
*/

int	is_printable(char c)
{
  if (c >= 32 && c < 127)
    return (1);
  return (0);
}
