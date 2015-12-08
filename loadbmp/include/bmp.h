/*
** fire.h for fire in /home/alies/rendu/gfx_incendie
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 21:55:38 2015 Arnaud Alies
** Last update Tue Dec  8 17:00:25 2015 Arnaud Alies
*/

#ifndef BMP_H_
#define BMP_H_

#define WIDTH (800)
#define HEIGHT (600)
#define FPS (50)

#include <lapin.h>

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
} t_data;

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int color);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

t_bunny_pixelarray	*load_bitmap(const char *file);
void    		all_grey(t_bunny_pixelarray *pix);
void    		binarize(t_bunny_pixelarray *pix);

#endif
