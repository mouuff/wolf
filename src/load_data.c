/*
** load_data.c for data in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Dec 13 12:37:49 2015 Arnaud Alies
** Last update Sun Dec 13 21:56:54 2015 Arnaud Alies
*/

#include <stdlib.h>
#include "wolf.h"

void    free_data(t_data *data)
{
  int   x;

  x = 0;
  while (x <= ((data->map).ntextures))
    {
      bunny_delete_clipable(&(((data->map).textures)[x])->clipable);
      x += 1;
    }
}

int     reload_data(t_data *data, char *file)
{
  if (file == NULL)
    return (0);
  free_data(data);
  if (init_data(data, file))
    return (1);
  return (0);
}

int     init_data(t_data *data, char *file)
{
  if (load_map(file, &(data->map)))
    return (1);
  (data->pos).x = ((data->map).spawn)[S_X] + 0.5;
  (data->pos).y = ((data->map).spawn)[S_Y] + 0.4;
  data->ang = ((data->map).spawn)[S_ANG] / 180.0 * M_PI;
  return (0);
}
