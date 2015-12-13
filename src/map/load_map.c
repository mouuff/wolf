/*
** load_map.c for map load in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 10:39:51 2015 Arnaud Alies
** Last update Sun Dec 13 19:06:06 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <lapin.h>
#include "wolf.h"
#include "bmp.h"
#include "my.h"

int		ini_to_map(t_bunny_ini *ini, t_map *map)
{
  const char	*buf;

  if ((buf = bunny_ini_get_field(ini, SCOPE, "width", 0)) == NULL)
    return (INFO_ERR);
  map->width = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "height", 0)) == NULL)
    return (INFO_ERR);
  map->height = my_str_to_nbr(buf);
  if (set_map(ini, map))
    return (MAP_ERR);
  set_spawn(ini, map);
  set_exit(ini, map);
  return (0);
}

int		load_map(char *ini_name, t_map *map)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(ini_name)) == NULL)
    {
      my_putstr("File not found.\n");
      return (1);
    }
  if (ini_to_map(ini, map))
    {
      my_putstr("Malformated file. (height/width too small? / wrong scope?\n");
      return (1);
    }
  if (set_textures(ini, map))
    {
      my_putstr("Error while loading textures\n");
      return (1);
    }
  bunny_delete_ini(ini);
  return (0);
}
