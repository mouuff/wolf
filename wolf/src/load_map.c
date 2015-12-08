/*
** load_map.c for map load in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 10:39:51 2015 Arnaud Alies
** Last update Fri Dec  4 14:23:56 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <lapin.h>
#include "wolf.h"
#include "my.h"

int     	set_map(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;
  int		size;
  int		x;

  size = map->width * map->height;
  if ((map->matrix = malloc(sizeof(int) * (size + 1))) == NULL)
    return (1);
  x = 0;
  while (x < size)
    {
      if ((buf = bunny_ini_get_field(ini, SCOPE, "map", x)) == NULL)
	return (1);
      (map->matrix)[x] = my_str_to_nbr(buf);
      x += 1;
    }
  return (0);
}

int		ini_to_map(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;

  if ((buf = bunny_ini_get_field(ini, SCOPE, "width", 0)) == NULL)
    return (1);
  map->width = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "height", 0)) == NULL)
    return (1);
  map->height = my_str_to_nbr(buf);
  if (set_map(ini, map))
    return (1);
  return (0);
}

t_map		*load_map(char *ini_name)
{
  t_map		*map;
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(ini_name)) == NULL)
    return (NULL);
  if ((map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  if (ini_to_map(ini, map))
    return (NULL);
  return (map);
}
