/*
** map.c for map in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 14:07:32 2015 Arnaud Alies
** Last update Wed Dec  9 13:40:55 2015 Arnaud Alies
*/

#include "my.h"
#include "wolf.h"

void	show_map(t_map *map)
{
  int	x;
  int	y;

  y = 0;
  x = 0;
  my_printf("size: %d %d\n", map->width, map->height);
  while (x < map->width * map->height)
    {
      if (y == map->width)
	{
	  y = 0;
	  my_putchar('\n');
	}
      my_printf("%d, ", (map->matrix)[x]);
      x += 1;
      y += 1;
    }
  my_putchar('\n');
}
