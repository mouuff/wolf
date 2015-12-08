/*
** tekfill.c for tek fill in /home/alies/rendu/gfx_fdf1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Nov 10 14:19:09 2015 Arnaud Alies
** Last update Wed Nov 18 15:18:34 2015 Arnaud Alies
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
