/*
** tekfill.c for tek fill in /home/alies/rendu/gfx_fdf1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Nov 10 14:19:09 2015 Arnaud Alies
** Last update Wed Dec  9 13:47:11 2015 Arnaud Alies
*/

#include <lapin.h>

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int ground,
		unsigned int air)
{
  int	x;
  int   w;
  int	h;

  x = 0;
  h = (pix->clipable).clip_height;
  w = (pix->clipable).clip_width;
  while (h * w > x)
    {
      if ((h * w) / 2 > x)
	(((t_color*)pix->pixels)[x]).full = ground;
      else
	(((t_color*)pix->pixels)[x]).full = air;
      x += 1;
    }
}
