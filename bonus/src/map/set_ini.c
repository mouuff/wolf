/*
** set_ini.c for set ini in /home/alies/rendu/gfx_wolf3d/src/map
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Dec 13 12:13:23 2015 Arnaud Alies
** Last update Sun Dec 13 19:13:07 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"
#include "wolf.h"
#include "bmp.h"

void            set_spawn(t_bunny_ini *ini, t_map *map)
{
  const char    *buf;

  (map->spawn)[S_X] = 1;
  (map->spawn)[S_Y] = 1;
  (map->spawn)[S_ANG] = 0;
  if ((buf = bunny_ini_get_field(ini, SCOPE, "spawn", S_X)) != NULL)
    (map->spawn)[S_X] = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "spawn", S_Y)) != NULL)
    (map->spawn)[S_Y] = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "spawn", S_ANG)) != NULL)
    (map->spawn)[S_ANG] = my_str_to_nbr(buf);
}

void            set_exit(t_bunny_ini *ini, t_map *map)
{
  const char    *buf;

  (map->exit)[S_X] = -1;
  (map->exit)[S_Y] = -1;
  if ((buf = bunny_ini_get_field(ini, SCOPE, "exit", S_X)) != NULL)
    (map->exit)[S_X] = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "exit", S_Y)) != NULL)
    (map->exit)[S_Y] = my_str_to_nbr(buf);
  if ((buf = bunny_ini_get_field(ini, SCOPE, "exit", 2)) != NULL)
    {
      if (map->next_map != NULL)
	bunny_free(map->next_map);
      map->next_map = my_strdup(buf);
    }
}

int             set_map(t_bunny_ini *ini, t_map *map)
{
  const char    *buf;
  int           size;
  int           x;

  size = map->width * map->height;
  if (map->matrix != NULL)
    bunny_free(map->matrix);
  if ((map->matrix = bunny_malloc(sizeof(int) * (size + 1))) == NULL)
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

int             set_textures(t_bunny_ini *ini, t_map *map)
{
  const char    *buf;

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
