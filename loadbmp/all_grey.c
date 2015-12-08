/*
** all_grey.c for all grey in /home/alies/rendu/binarizer_2020
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Dec  8 15:09:02 2015 Arnaud Alies
** Last update Tue Dec  8 18:42:25 2015 Arnaud Alies
*/

#include <lapin.h>

void    	all_grey(t_bunny_pixelarray *pix)
{
  t_color	buff;
  int		mid;
  int		pos;
  int   	w;
  int   	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  pos = 0;
  while (pos < w * h)
    {
      buff = (((t_color*)pix->pixels)[pos]);
      mid = (buff.argb[0] + buff.argb[1] + buff.argb[2]) / 3;
      (((t_color*)pix->pixels)[pos]).argb[0] = mid;
      (((t_color*)pix->pixels)[pos]).argb[1] = mid;
      (((t_color*)pix->pixels)[pos]).argb[2] = mid;
      pos += 1;
    }
}
