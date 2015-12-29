/*
** disp.c for disp in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  9 13:27:44 2015 Arnaud Alies
** Last update Tue Dec 29 17:45:42 2015 Arnaud Alies
*/

#include "wolf.h"
#include "disp.h"

void			disp_loop(t_disp *dsp, t_data *data)
{
  t_bunny_position	text;
  t_color		c;
  float			tmp;

  while ((dsp->pos).y < dsp->height + dsp->space &&
	 (dsp->pos).y < HEIGHT)
    {
      tmp = ((dsp->hit)->type == A_Y ?
	     ((dsp->hit)->pos).x :
	     ((dsp->hit)->pos).y);
      text.x = MAP(tmp,
		   (int)tmp, (int)(tmp + 1),
		   0, ((dsp->texture)->clipable).clip_width);
      text.y = MAP((float)(dsp->pos).y,
		   dsp->space, (dsp->height + dsp->space),
		   0, ((dsp->texture)->clipable).clip_height);
      c = get_pixel((dsp->texture), &text);
      tekpixel(data->pix, &(dsp->pos), &c);
      (dsp->pos).y += 1;
    }
}

void		disp_wall(t_data *data,
			  int col,
			  t_hit *hit)
{
  t_disp	dsp;

  if (hit->type == A_U)
    return ;
  dsp.hit = hit;
  dsp.height = ((float)HEIGHT / hit->k);
  dsp.space = (HEIGHT - dsp.height) / 2.0;
  (dsp.pos).x = col;
  (dsp.pos).y = (dsp.space < 0 ? 0 : dsp.space);
  if ((data->map).ntextures > hit->hit - 1)
    (dsp.texture) = ((data->map).textures)[hit->hit];
  else
    (dsp.texture) = ((data->map).textures)[0];
  disp_loop(&dsp, data);
}

void    wolf(t_data *data)
{
  t_hit	hit;
  t_pt	ray;
  int	i;

  pixfill(data->pix, GROUND_COLOR, AIR_COLOR);
  i = 0;
  while (i < WIDTH + DECAL)
    {
      ray = get_ray(i);
      ray = rotate_ray(ray, data->ang);
      hit = check_grid(data->pos, ray, data);
      disp_wall(data, i, &hit);
      i += 1;
    }
}
