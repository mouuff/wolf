/*
** map.c for map in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 14:07:32 2015 Arnaud Alies
** Last update Mon Dec  7 21:08:41 2015 Arnaud Alies
*/

#include <math.h>
#include <stdlib.h>
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

int	check_wall(t_map *map, int x, int y)
{
  if ((x < map->width && x >= 0) && (y < map->height && y >= 0))
    return ((map->matrix)[x + map->width * y]);
  return (0);
}
