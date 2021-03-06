/*
** wolf.h for wolf in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:33:09 2015 Arnaud Alies
** Last update Fri Oct  7 14:15:59 2016 alies_a
*/

#ifndef WOLF_H_
#define WOLF_H_

#include <lapin.h>

#define WIDTH (700)
#define HEIGHT (500)
#define FPS (40)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define GETK(x, xz, vx) ((x - xz) / vx)
#define GETX(xz, k, vx) (xz + (k * vx))

#define SCOPE "mou"
#define FOV (1.5)
#define DIS (1.0)

#define GROUND_COLOR (0x5B5B5B)
#define AIR_COLOR (0x3D3F4D)
#define MAX_TEX (25)

#ifndef M_PI
#define M_PI 3.1415
#endif

typedef enum e_error
  {
    MAP_ERR,
    INFO_ERR,
    LOAD_ERR
  } t_error;

typedef enum e_axes
  {
    A_U,
    A_X,
    A_Y
  } t_axes;

typedef enum e_spawn
  {
    S_X		= 0,
    S_Y		= 1,
    S_ANG	= 2,
    S_SIZE	= 3
  } t_spawn;

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
  int spawn[S_SIZE];
  char *next_map;
  int exit[2];
  t_bunny_pixelarray *textures[MAX_TEX];
  int ntextures;
} t_map;

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  t_map	map;
  t_pt pos;
  float ang;
  int antialiasing;
  const bool *keys;
} t_data;

int	check_wall(t_map *map, int x, int y);
t_pt	get_ray(int x);
t_pt    rotate_ray(t_pt ray, float ang);

t_hit   check_line_x(t_pt start, t_pt ray, int nline, t_data *data);
t_hit   check_line_y(t_pt start, t_pt ray, int nline, t_data *data);
t_hit   check_grid(t_pt start, t_pt ray, t_data *data);

void    antialiasing(t_bunny_pixelarray *pix);
void    pixfill(t_bunny_pixelarray *pix,
		unsigned int ground,
		unsigned int air);
void	disp_wall(t_data *data, int col, t_hit *hit);
void    wolf(t_data *data);

int	load_map(char *ini_name, t_map *map);
int	set_textures(t_bunny_ini *ini, t_map *map);
int	set_map(t_bunny_ini *ini, t_map *map);
void	set_exit(t_bunny_ini *ini, t_map *map);
void	set_spawn(t_bunny_ini *ini, t_map *map);

void    free_data(t_data *data);
int     reload_data(t_data *data, char *file);
int     init_data(t_data *data, char *file);

t_color	get_pixel(t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

int	hit_exit(t_data *data);
int     walk(t_data *data, int speed);
int	move(t_data *data);

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
