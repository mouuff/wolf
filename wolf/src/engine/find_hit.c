/*
** find_hit.c for find hit in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 13:22:38 2015 Arnaud Alies
** Last update Fri Dec 11 11:21:47 2015 Arnaud Alies
*/

#include "wolf.h"

int     check_wall(t_map *map, int x, int y)
{
  if ((x < map->width && x >= 0) && (y < map->height && y >= 0))
    return ((map->matrix)[x + map->width * y]);
  return (0);
}

t_hit   check_line_x(t_pt start, t_pt ray, int nline, t_data *data)
{
  t_hit res;

  res.type = A_X;
  (res.pos).x = nline;
  res.k = GETK((float)nline, start.x, ray.x);
  (res.pos).y = GETX(start.y, res.k, ray.y);
  res.hit = check_wall(data->map, (res.pos).x - (start.x < nline ? 0 : 1), (res.pos).y);
  return (res);
}

t_hit   check_line_y(t_pt start, t_pt ray, int nline, t_data *data)
{
  t_hit res;

  res.type = A_Y;
  (res.pos).y = nline;
  res.k = GETK((float)nline, start.y, ray.y);
  (res.pos).x = GETX(start.x, res.k, ray.x);
  res.hit = check_wall(data->map, (res.pos).x, (res.pos).y - (start.y < nline ? 0 : 1));
  return (res);
}

t_hit   check_grid(t_pt start, t_pt ray, t_data *data)
{
  t_hit hit;
  t_hit low;
  int   nline;

  low.k = (data->map)->width * (data->map)->height;
  nline = 0;
  while (nline < (data->map)->width)
    {
      hit = check_line_x(start, ray, nline, data);
      if (hit.k > 0 && hit.k < low.k && hit.hit > 0)
	low = hit;
      nline += 1;
    }
  nline = 0;
  while (nline < (data->map)->height)
    {
      hit = check_line_y(start, ray, nline, data);
      if (hit.k > 0 && hit.k < low.k && hit.hit > 0)
	low = hit;
      nline += 1;
    }
  return (low);
}
