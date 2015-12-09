/*
** disp.c for disp in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 13:27:44 2015 Arnaud Alies
** Last update Wed Dec  9 16:42:23 2015 Arnaud Alies
*/

#include "wolf.h"

void                    disp_wall(t_bunny_pixelarray *pix,
				  int col,
				  float k)
{
  t_bunny_position      pos;
  t_color               c;
  int                   y;
  int                   height;
  int                   space;
  unsigned int		darkness;

  pos.x = col;
  c.full = BLUE;
  height = ((float)HEIGHT / k);
  space = (HEIGHT - height) / 2.0;
  y = space;
  while (y < height + space)
    {
      pos.y = y;
      darkness = MAP((float)height, 0, HEIGHT, 0, 255);
      darkness = (darkness > 255 ? 255 : darkness);
      c.argb[0] = darkness;
      c.argb[1] = darkness;
      c.argb[2] = darkness;
      tekpixel(pix, &pos, &c);
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
      disp_wall(data->pix, i, hit.k);
      i += 1;
    }
}
