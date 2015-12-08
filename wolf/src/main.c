/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Tue Dec  8 20:59:10 2015 Arnaud Alies
*/

#include <lapin.h>
#include "wolf.h"


t_hit	check_line_x(t_pt start, t_pt ray, int nline, t_data *data)
{
  t_hit	res;

  (res.pos).x = nline;
  res.k = GETK((float)nline, start.x, ray.x);
  (res.pos).y = GETX(start.y, res.k, ray.y);
  res.hit = check_wall(data->map, (res.pos).x - (start.x < nline ? 0 : 1), (res.pos).y);
  return (res);
}

t_hit   check_line_y(t_pt start, t_pt ray, int nline, t_data *data)
{
  t_hit res;

  (res.pos).y = nline;
  res.k = GETK((float)nline, start.y, ray.y);
  (res.pos).x = GETX(start.x, res.k, ray.x);
  res.hit = check_wall(data->map, (res.pos).x, (res.pos).y - (start.y < nline ? 0 : 1));
  return (res);
}

t_hit	check_grid(t_pt start, t_pt ray, t_data *data)
{
  t_hit	hit;
  t_hit	low;
  int	nline;

  low.k = 10000;
  nline = 0;
  while (nline < WIDTH)
    {
      hit = check_line_x(start, ray, nline, data);
      if (hit.k > 0 && hit.k < low.k && hit.hit == 1)
	low = hit;
      nline += 1;
    }
  nline = 0;
  while (nline < HEIGHT)
    {
      hit = check_line_y(start, ray, nline, data);
      if (hit.k > 0 && hit.k < low.k && hit.hit == 1)
	low = hit;
      nline += 1;
    }
  return (low);
}

void                    disp_wall(t_bunny_pixelarray *pix,
				  int col,
				  float k)
{
  t_bunny_position      pos;
  t_color               c;
  int                   y;
  int                   height;
  int                   space;

  pos.x = col;
  c.full = BLUE;
  height = ((float)HEIGHT / k);
  printf("%d\n", height);
  space = (HEIGHT - height) / 2.0;
  y = space;
  printf("SPACE : %d\n", space);
  while (y < height + space)
    {
      pos.y = y;
      tekpixel(pix, &pos, &c);
      y += 1;
    }
}

void	test(t_data *data)
{
  t_hit hit;
  t_pt ray;
  int  i;

  i = 0;
  while (i < WIDTH)
    {
      ray = get_ray(i);
      ray = rotate_ray(ray, data->ang);
      printf("x = %f; y = %f", ray.x, ray.y);
      hit = check_grid(data->pos, ray, data);
      //hit = check_line_y(data->pos, ray, 1, data);
      //hit = check_line_x(data->pos, ray, 6, data);
      printf(" || %f %f ; k: %f h: %d\n",
	     (hit.pos).x,
	     (hit.pos).y,
	     hit.k,
	     hit.hit);
      disp_wall(data->pix, i, hit.k);
      i += 1;
    }
}

int	init_data(t_data *data)
{
  (data->pos).x = 5;
  (data->pos).y = 5;
  data->ang = -3.1415 / 3;
  data->map = load_map("maps/map1.ini");
  if (data->map == NULL)
    return (1);
  show_map(data->map);
  return (0);
}


static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  pixfill(data->pix, WHITE);
  test(data);
  //return (EXIT_ON_SUCCESS);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data	*data;

  data = (t_data*)data_pt;
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && keysym == BKS_D)
    data->ang -= 0.05;
  if (state == GO_DOWN && keysym == BKS_Q)
    data->ang += 0.05;
  if (state == GO_DOWN && keysym == BKS_Z)
    {
      (data->pos).x += cos(data->ang) / 5;
      (data->pos).y += sin(data->ang) / 5;
    }
  if (state == GO_DOWN && keysym == BKS_S)
    {
      (data->pos).x -= cos(data->ang) / 5;
      (data->pos).y -= sin(data->ang) / 5;
    }
  return (GO_ON);
}


int		main(int ac, char **av)
{
  t_data	data;

  if (init_data(&data))
    return (1);
  data.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  data.win = bunny_start(WIDTH, HEIGHT, false, "Wolf");
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
