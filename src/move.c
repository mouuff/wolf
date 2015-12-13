/*
** move.c for move in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Dec 13 12:25:13 2015 Arnaud Alies
** Last update Sun Dec 13 21:55:40 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <math.h>
#include "wolf.h"

int	hit_exit(t_data *data)
{
  if ((data->map).next_map == NULL)
    return (0);
  if ((int)(data->pos).x == ((data->map).exit)[0] &&
      (int)(data->pos).y == ((data->map).exit)[1])
    {
      if (reload_data(data, (data->map).next_map))
	return (1);
    }
  return (0);
}

int     walk(t_data *data, int speed)
{
  t_pt  new;

  new.x = (data->pos).x + cos(data->ang) / 10 * speed;
  new.y = (data->pos).y;
  if (check_wall(&(data->map), new.x, new.y) <= 1)
    (data->pos) = new;
  new.x = (data->pos).x;
  new.y = (data->pos).y + sin(data->ang) / 10 * speed;
  if (check_wall(&(data->map), new.x, new.y) <= 1)
    (data->pos) = new;
  return (0);
}


int	move(t_data *data)
{
  if (data->keys != NULL)
    {
      if (data->keys[BKS_D])
	data->ang -= 0.05;
      if (data->keys[BKS_Q])
	data->ang += 0.05;
      if (data->keys[BKS_Z])
	walk(data, 1);
      if (data->keys[BKS_S])
	walk(data, -1);
    }
  if (hit_exit(data))
    return (1);
  return (0);
}
