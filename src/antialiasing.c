/*
** antialiasing.c for anti aliasing in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Dec 14 21:51:15 2015 Arnaud Alies
** Last update Mon Dec 14 21:55:18 2015 Arnaud Alies
*/

#include <lapin.h>
#include "wolf.h"

t_color         moy_color(t_color a, t_color b, t_color c)
{
  t_color       new;

  new.argb[0] = (a.argb[0] + b.argb[0] + c.argb[0]) / 3.0;
  new.argb[1] = (a.argb[1] + b.argb[1] + c.argb[1]) / 3.0;
  new.argb[2] = (a.argb[2] + b.argb[2] + c.argb[2]) / 3.0;
  new.argb[3] = (a.argb[3] + b.argb[3] + c.argb[3]) / 3.0;
  return (new);
}

t_color         moy_pt(t_bunny_pixelarray *pix,
		      t_bunny_position *pos)
{
  t_bunny_position      left;
  t_bunny_position      bot;
  int                   w;
  int                   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if (pos->x + 1 < w && pos->y + 1 < h)
    {
      left.x = pos->x + 1;
      left.y = pos->y;
      bot.x = pos->x;
      bot.y = pos->y + 1;
      return (moy_color(get_pixel(pix, pos),
			get_pixel(pix, &left),
			get_pixel(pix, &bot)));
    }
  return (get_pixel(pix, pos));
}

void    antialiasing(t_bunny_pixelarray *pix)
{
  t_bunny_position      pos;
  t_color               moy;
  int                   w;
  int                   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  pos.x = 0;
  pos.y = 0;
  while (pos.y < h)
    {
      moy = moy_pt(pix, &pos);
      tekpixel(pix, &pos, &moy);
      pos.x += 1;
      if (pos.x > w)
	{
	  pos.x = 0;
	  pos.y += 1;
	}
    }
}
