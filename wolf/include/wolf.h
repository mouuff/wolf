/*
** wolf.h for wolf in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:33:09 2015 Arnaud Alies
** Last update Fri Dec 11 21:27:21 2015 Arnaud Alies
*/

#ifndef WOLF_H_
#define WOLF_H_

#define WIDTH (700)
#define HEIGHT (500)
#define FPS (40)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define GETK(x, xz, vx) ((x - xz) / vx)
#define GETX(xz, k, vx) (xz + (k * vx))

#define SCOPE "mou"
#define FOV (1.5)
#define DIS (1.0)

#define DARK_BROWN (0x5B5B5B)
#define DARK_RED (0x3D3F4D)
#define MAX_TEX (25)

#include <lapin.h>

typedef enum e_error
  {
    MAP_ERR,
    INFO_ERR,
    LOAD_ERR,
  } t_error;

typedef enum e_axes
  {
    A_X,
    A_Y,
  } t_axes;

typedef	struct s_pt
{
  float	x;
  float	y;
} t_pt;

typedef struct s_hit
{
  t_pt pos;
  float k;
  int type;
  int hit;
} t_hit;

typedef struct s_map
{
  int *matrix;
  int width;
  int height;
  int spawn[2];
  t_bunny_pixelarray *textures[MAX_TEX];
  int ntextures;
} t_map;

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  t_map	*map;
  t_pt pos;
  float ang;
  const bool *keys;
} t_data;

int	check_wall(t_map *map, int x, int y);
t_pt	get_ray(int x);
t_pt    rotate_ray(t_pt ray, float ang);

t_hit   check_line_x(t_pt start, t_pt ray, int nline, t_data *data);
t_hit   check_line_y(t_pt start, t_pt ray, int nline, t_data *data);
t_hit   check_grid(t_pt start, t_pt ray, t_data *data);

void    pixfill(t_bunny_pixelarray *pix,
		unsigned int ground,
		unsigned int air);
void	disp_wall(t_data *data, int col, t_hit *hit);
void    wolf(t_data *data);

t_map	*load_map(char *ini_name);
void    show_map(t_map *map);
t_color	get_pixel(t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);
double	vecnorm(t_bunny_position *coord0,
		t_bunny_position *coord1);
void    go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move);

#endif
