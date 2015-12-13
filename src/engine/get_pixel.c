/*
** get_pixel.c for get_pixel in /home/alies/rendu/gfx_wolf3d/src/engine
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec 11 16:46:09 2015 Arnaud Alies
** Last update Fri Dec 11 16:46:24 2015 Arnaud Alies
*/

#include <lapin.h>

t_color         get_pixel(t_bunny_pixelarray *pix,
			  t_bunny_position *pos)
{
  t_color       color;
  int           w;
  int           h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    color.full = (((t_color*)pix->pixels)[w * pos->y + pos->x]).full;
  else
    color.full = BLACK;
  return (color);
}
