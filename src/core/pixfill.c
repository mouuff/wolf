/*
** pixfill.c for fill pixelarray in /home/alies/rendu/gfx_incendie/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 22:15:14 2015 Arnaud Alies
** Last update Fri Dec  4 22:15:15 2015 Arnaud Alies
*/

#include <lapin.h>

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int color)
{
  int	x;
  int   w;
  int	h;

  x = 0;
  h = (pix->clipable).clip_height;
  w = (pix->clipable).clip_width;
  while (h * w > x)
    {
      (((t_color*)pix->pixels)[x]).full = color;
      x += 1;
    }
}
