/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Tue Dec 29 17:56:16 2015 Arnaud Alies
*/

#include <math.h>
#include <lapin.h>
#include "bmp.h"
#include "wolf.h"

int     mv(t_data *data, float speed)
{
  t_pt  new;
  float	ang;

  ang = data->ang + M_PI / 2;
  new.x = (data->pos).x + cos(ang) / 10 * speed;
  new.y = (data->pos).y;
  if (check_wall(&(data->map), new.x, new.y) <= 1)
    (data->pos) = new;
  new.x = (data->pos).x;
  new.y = (data->pos).y + sin(ang) / 10 * speed;
  if (check_wall(&(data->map), new.x, new.y) <= 1)
    (data->pos) = new;
  return (0);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  if (move(data))
    return (EXIT_ON_ERROR);
  wolf(data);
  if (data->antialiasing)
    antialiasing(data->pix);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  zero.x = WIDTH - DECAL;
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
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && keysym == BKS_A)
    {
      data->antialiasing = (data->antialiasing ? 0 : 1);
    }
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  data.antialiasing = 0;
  data.keys = NULL;
  (data.map).matrix = NULL;
  (data.map).next_map = NULL;
  if (ac <= 1)
    init_data(&data, "maps/camp1.ini");
  else if (init_data(&data, av[1]))
    return (1);
  if ((data.pix = bunny_new_pixelarray(WIDTH + DECAL, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH * 2, HEIGHT, false, "Wolf")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
