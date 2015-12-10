/*
** fire.h for fire in /home/alies/rendu/gfx_incendie
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 21:55:38 2015 Arnaud Alies
** Last update Thu Dec 10 16:30:09 2015 Arnaud Alies
*/

#ifndef BMP_H_
#define BMP_H_

#define WIDTH (800)
#define HEIGHT (600)
#define FPS (50)

#include <lapin.h>
#include <stdint.h>

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
} t_data;

typedef struct s_head{
  uint16_t type;
  uint32_t size;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t offset;
} __attribute__((packed)) t_head;

typedef struct s_info{
  uint32_t size;
  int32_t width;
  int32_t height;
  uint16_t planes;
  uint16_t bits;
  uint32_t compression;
  uint32_t imagesize;
  int32_t xresolution;
  int32_t yresolution;
  uint32_t ncolours;
  uint32_t importantcolours;
} __attribute__((packed)) t_info;

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int color);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

t_bunny_pixelarray	*load_bitmap(const char *file);
void    		all_grey(t_bunny_pixelarray *pix);
void    		binarize(t_bunny_pixelarray *pix);

#endif
