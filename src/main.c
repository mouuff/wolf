/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Sun Jan  3 19:34:38 2016 Arnaud Alies
*/

#include <math.h>
#include <lapin.h>
#include "bmp.h"
#include "wolf.h"

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
    {
      if (init_data(&data, "maps/camp1.ini"))
	return (1);
    }
  else if (init_data(&data, av[1]))
    return (1);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "Wolf")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
