/*
** disp.c for disp in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 13:27:44 2015 Arnaud Alies
** Last update Thu Dec 10 20:44:00 2015 Arnaud Alies
*/

#include <math.h>
#include "wolf.h"

t_color		get_pixel(t_bunny_pixelarray *pix,
			  t_bunny_position *pos)
{
  t_color	color;
  int   	w;
  int   	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    color.full = (((t_color*)pix->pixels)[w * pos->y + pos->x]).full;
  else
    color.full = BLACK;
  return (color);
}

void                    disp_wall(t_data *data,
				  int col,
				  t_hit *hit)
{
  t_bunny_position      pos;
  t_bunny_position	text;
  t_color               c;
  int                   y;
  int                   height;
  int                   space;
  unsigned int		darkness;

  pos.x = col;
  c.full = BLUE;
  height = ((float)HEIGHT / hit->k);
  space = (HEIGHT - height) / 2.0;
  y = space;
  while (y < height + space)
    {
      pos.y = y;
      if (hit->type == A_Y)
	{
	  text.x = MAP((hit->pos).x,
		       floor((hit->pos).x), ceil((hit->pos).x),
		       0, ((data->texture)->clipable).clip_width);
	}
      else
	{
	  text.x = MAP((hit->pos).y,
		       (int)(hit->pos).y, ((int)(hit->pos).y + 1),
		       0, ((data->texture)->clipable).clip_width);
	}
      text.y = MAP((float)y,
		   space, (height + space),
		   0, ((data->texture)->clipable).clip_height);
      c = get_pixel(data->texture, &text);
      tekpixel(data->pix, &pos, &c);
      y += 1;
    }
}

void    wolf(t_data *data)
{
  t_hit	hit;
  t_pt	ray;
  int	i;

  pixfill(data->pix, DARK_RED, DARK_BROWN);
  i = 0;
  while (i < WIDTH)
    {
      ray = get_ray(i);
      ray = rotate_ray(ray, data->ang);
      hit = check_grid(data->pos, ray, data);
      disp_wall(data, i, &hit);
      i += 1;
    }
}
