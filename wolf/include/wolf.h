/*
** wolf.h for wolf in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:33:09 2015 Arnaud Alies
** Last update Tue Dec  8 20:41:39 2015 Arnaud Alies
*/

#ifndef WOLF_H_
#define WOLF_H_

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (30)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define GETK(x, xz, vx) ((x - xz) / vx)
#define GETX(xz, k, vx) (xz + (k * vx))

#define SCOPE "mou"
#define FOV (1.0)
#define DIS (2.5)

#include <lapin.h>

typedef	struct s_pt
{
  float	x;
  float	y;
} t_pt;

typedef struct s_hit
{
  t_pt pos;
  float k;
  int hit;
} t_hit;

typedef struct s_map
{
  int *matrix;
  int width;
  int height;
} t_map;

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  t_map	*map;
  t_pt pos;
  float ang;
} t_data;

int	check_wall(t_map *map, int x, int y);

t_pt	get_ray(int x);
t_pt    rotate_ray(t_pt ray, float ang);

t_map	*load_map(char *ini_name);
void    show_map(t_map *map);
float	inter(t_map *map, float x, float y, float ang);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int color);

#endif
