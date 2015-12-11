/*
** load_map.c for map load in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 10:39:51 2015 Arnaud Alies
** Last update Fri Dec 11 16:14:21 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <lapin.h>
#include "wolf.h"
#include "bmp.h"
#include "my.h"

int     	set_map(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;
  int		size;
  int		x;

  size = map->width * map->height;
  if ((map->matrix = malloc(sizeof(int) * (size + 1))) == NULL)
    return (MAP_ERR);
  x = 0;
  while (x < size)
    {
      if ((buf = bunny_ini_get_field(ini, SCOPE, "map", x)) == NULL)
	return (MAP_ERR);
      (map->matrix)[x] = my_str_to_nbr(buf);
      x += 1;
    }
  return (0);
}

int		ini_to_map(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;

  (map->spawn)[0] = 1;
  (map->spawn)[1] = 1;
  if ((buf = bunny_ini_get_field(ini, SCOPE, "width", 0)) == NULL)
    return (INFO_ERR);
  map->width = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "height", 0)) == NULL)
    return (INFO_ERR);
  map->height = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "spawn", 0)) != NULL)
    (map->spawn)[0] = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "spawn", 1)) != NULL)
    (map->spawn)[1] = my_str_to_nbr(buf);
  if (set_map(ini, map))
    return (MAP_ERR);
  return (0);
}

int		ini_textures(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;

  if (((map->textures)[0] = bunny_new_pixelarray(100, 100)) == NULL)
    return (1);
  map->ntextures = 0;
  while ((buf = bunny_ini_get_field(ini, SCOPE, "textures",
				    map->ntextures)) != NULL)
    {
      if (((map->textures)[map->ntextures + 1] = load_bitmap(buf)) == NULL)
	return (1);
      map->ntextures += 1;
      if (map->ntextures > MAX_TEX)
	return (1);
    }
  return (0);
}

t_map		*load_map(char *ini_name)
{
  t_map		*map;
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(ini_name)) == NULL)
    {
      my_putstr("File not found.\n");
      return (NULL);
    }
  if ((map = malloc(sizeof(t_map))) == NULL)
    {
      my_putstr("Could not allocate.\n");
      return (NULL);
    }
  if (ini_to_map(ini, map))
    {
      my_putstr("Malformated file. (height/width too small? / wrong scope?\n");
      return (NULL);
    }
  if (ini_textures(ini, map))
    {
      my_putstr("Error while loading textures\n");
      return (NULL);
    }
  return (map);
}
