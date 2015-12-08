/*
** tekpixel.c for set pixel in /home/alies/rendu/gfx_incendie/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 22:15:32 2015 Arnaud Alies
** Last update Sat Dec  5 14:28:27 2015 Arnaud Alies
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   w;
  int	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}
